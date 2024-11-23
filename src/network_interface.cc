#include <iostream>

#include "address.hh"
#include "arp_message.hh"
#include "exception.hh"
#include "network_interface.hh"
#include <assert.h>

using namespace std;

//! \param[in] ethernet_address Ethernet (what ARP calls "hardware") address of the interface
//! \param[in] ip_address IP (what ARP calls "protocol") address of the interface
NetworkInterface::NetworkInterface( string_view name,
                                    shared_ptr<OutputPort> port,
                                    const EthernetAddress& ethernet_address,
                                    const Address& ip_address )
  : name_( name )
  , port_( notnull( "OutputPort", move( port ) ) )
  , ethernet_address_( ethernet_address )
  , ip_address_( ip_address )
{
  cerr << "DEBUG: Network interface has Ethernet address " << to_string( ethernet_address ) << " and IP address "
       << ip_address.ip() << "\n";
}

//! \param[in] dgram the IPv4 datagram to be sent
//! \param[in] next_hop the IP address of the interface to send it to (typically a router or default gateway, but
//! may also be another host if directly connected to the same network as the destination) Note: the Address type
//! can be converted to a uint32_t (raw 32-bit IP address) by using the Address::ipv4_numeric() method.
void NetworkInterface::send_datagram( const InternetDatagram& dgram, const Address& next_hop )
{
  // Your code here.
  if ( arp_table.find( next_hop.ipv4_numeric() ) != arp_table.end() ) {
    EthernetFrame res;
    res.header = { arp_table[next_hop.ipv4_numeric()].addr, ethernet_address_, EthernetHeader::TYPE_IPv4 };
    res.payload = serialize( dgram );
    transmit( res );
  } else {
    int flag = 0;
    for ( auto& it : waitlist ) {
      if ( it.second.first == next_hop && it.second.second > 0 ) {
        flag = 1;
        break;
      }
    }
    if ( flag == 1 )
      return;
    ARPMessage res;
    res.opcode = ARPMessage::OPCODE_REQUEST;
    res.sender_ip_address = ip_address_.ipv4_numeric();
    res.sender_ethernet_address = ethernet_address_;
    res.target_ip_address = next_hop.ipv4_numeric();

    EthernetFrame res1;
    res1.header = { ETHERNET_BROADCAST, ethernet_address_, EthernetHeader::TYPE_ARP };
    res1.payload = serialize( res );
    transmit( res1 );
    waitlist.push_back( make_pair( dgram, make_pair( next_hop, 5000 ) ) );
  }
}

//! \param[in] frame the incoming Ethernet frame
void NetworkInterface::recv_frame( const EthernetFrame& frame )
{
  // Your code here.
  if ( frame.header.dst != ethernet_address_ && frame.header.dst != ETHERNET_BROADCAST )
    return;
  if ( frame.header.type == EthernetHeader::TYPE_ARP ) {
    ARPMessage res;
    if ( parse( res, frame.payload ) ) {
      if ( res.opcode == ARPMessage::OPCODE_REQUEST
           && ip_address_ == Address::from_ipv4_numeric( res.target_ip_address ) ) {
        ARPMessage res2;
        res2.opcode = ARPMessage::OPCODE_REPLY;
        res2.sender_ip_address = ip_address_.ipv4_numeric();
        res2.sender_ethernet_address = ethernet_address_;
        res2.target_ip_address = res.sender_ip_address;
        res2.target_ethernet_address = res.sender_ethernet_address;

        EthernetFrame res1;
        res1.header = { res.sender_ethernet_address, ethernet_address_, EthernetHeader::TYPE_ARP };
        res1.payload = serialize( res2 );
        transmit( res1 );
      }
      node tmp;
      tmp.addr = res.sender_ethernet_address;
      tmp.ttl = (size_t)30000;
      arp_table[res.sender_ip_address] = tmp;
      vector<pair<InternetDatagram, pair<Address, int>>>::iterator it = waitlist.begin();
      for ( ; it != waitlist.end(); it++ ) {
        if ( it->second.first == Address::from_ipv4_numeric( res.sender_ip_address ) ) {
          send_datagram( it->first, it->second.first );
          waitlist.erase( it );
          break;
        }
      }
    }
  } else if ( frame.header.type == EthernetHeader::TYPE_IPv4 ) {
    InternetDatagram res;
    if ( parse( res, frame.payload ) ) {
      datagrams_received().push( res );
    }
  }
}

//! \param[in] ms_since_last_tick the number of milliseconds since the last call to this method
void NetworkInterface::tick( const size_t ms_since_last_tick )
{
  // Your code here.
  vector<uint32_t> toberm;
  for ( auto& it : arp_table ) {
    it.second.ttl -= ms_since_last_tick;
    if ( it.second.ttl <= 0 )
      toberm.push_back( it.first );
  }
  for ( size_t i = 0; i < toberm.size(); i++ ) {
    arp_table.erase( toberm[i] );
  }
  for ( auto& it : waitlist ) {
    it.second.second -= ms_since_last_tick;
  }
  waitlist.erase( std::remove_if( waitlist.begin(),
                                  waitlist.end(),
                                  []( std::pair<InternetDatagram, std::pair<Address, int>>& element ) {
                                    return element.second.second <= 0;
                                  } ),
                  waitlist.end() );
}
