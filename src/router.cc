#include "router.hh"

#include <assert.h>
#include <iostream>
#include <limits>

using namespace std;

// route_prefix: The "up-to-32-bit" IPv4 address prefix to match the datagram's destination address against
// prefix_length: For this route to be applicable, how many high-order (most-significant) bits of
//    the route_prefix will need to match the corresponding bits of the datagram's destination address?
// next_hop: The IP address of the next hop. Will be empty if the network is directly attached to the router (in
//    which case, the next hop address should be the datagram's final destination).
// interface_num: The index of the interface to send the datagram out on.
void Router::add_route( const uint32_t route_prefix,
                        const uint8_t prefix_length,
                        const optional<Address> next_hop,
                        const size_t interface_num )
{
  cerr << "DEBUG: adding route " << Address::from_ipv4_numeric( route_prefix ).ip() << "/"
       << static_cast<int>( prefix_length ) << " => " << ( next_hop.has_value() ? next_hop->ip() : "(direct)" )
       << " on interface " << interface_num << "\n";

  // Your code here.
  table now;
  now.interface_num = interface_num;
  now.length = prefix_length;
  now.prefix = route_prefix;
  now.next_hop = next_hop;
  router_table.push_back( now );
}
size_t match( uint32_t a, uint32_t b, uint8_t prefixLen )
{
  uint32_t mask;
  if ( prefixLen == 32 )
    mask = 0xFFFFFFFF;
  else if ( prefixLen != 0 )
    mask = ( ( 1U << prefixLen ) - 1 ) << ( 32 - prefixLen );
  else
    mask = 0;
  uint32_t aMasked = a & mask;
  uint32_t bMasked = b & mask;
  if ( aMasked == bMasked ) {
    return prefixLen;
  }
  uint8_t matchLength = 0;
  for ( int i = 31; i >= 0; --i ) {
    if ( ( a & ( 1U << i ) ) == ( b & ( 1U << i ) ) ) {
      ++matchLength;
    } else {
      break;
    }
  }
  return min( matchLength, prefixLen );
}
// Go through all the interfaces, and route every incoming datagram to its proper outgoing interface.
void Router::route()
{
  // Your code here.
  for ( auto& interfacei : _interfaces ) {
    while ( !( interfacei->datagrams_received().empty() ) ) {
      InternetDatagram now = interfacei->datagrams_received().front();
      if ( now.header.ttl == 0 || now.header.ttl == 1 ) {
        interfacei->datagrams_received().pop();
        continue;
      }
      now.header.ttl--;
      now.header.compute_checksum();
      uint32_t dest = now.header.dst;
      size_t pos = 0, flag = 0;
      uint8_t len = 0;
      for ( size_t j = 0; j < router_table.size(); j++ ) {
        uint8_t curlen = match( dest, router_table[j].prefix, router_table[j].length );
        if ( curlen == router_table[j].length ) {
          if ( curlen > len || flag == 0 ) {
            len = curlen;
            flag = 1;
            pos = j;
          }
        }
      }
      if ( flag == 1 ) {
        if ( router_table[pos].next_hop.has_value() )
          interface( router_table[pos].interface_num )->send_datagram( now, router_table[pos].next_hop.value() );
        else
          interface( router_table[pos].interface_num )->send_datagram( now, Address::from_ipv4_numeric( dest ) );
      }
      interfacei->datagrams_received().pop();
    }
  }
}
