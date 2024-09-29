#include "reassembler.hh"
#include <assert.h>

using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring )
{
  // Your code here.
  if ( is_last_substring )
    eof_index = first_index + data.size();
  // first slice
  if ( first_index < expected ) {
    if ( expected - first_index > data.size() )
      return;
    uint64_t n = data.size();
    assert( expected - first_index <= data.size() );
    data = data.substr( expected - first_index, n - ( expected - first_index ) );
    first_index = expected;
  }
  if ( first_index - expected > output_.writer().available_capacity() )
    return;
  if ( first_index + data.size() - expected > output_.writer().available_capacity() ) {
    data = data.substr( 0, output_.writer().available_capacity() - ( first_index - expected ) );
  }
  // second slice(make sure buffer is sorted)
  vector<pair<uint64_t, string>> temp = {};
  pair<uint64_t, string> now;
  now.first = first_index, now.second = data;
  int flag = 0;
  for ( size_t i = 0; i < buffer.size(); i++ ) {
    uint64_t l = buffer[i].first, r = buffer[i].first + buffer[i].second.size() - 1;
    if ( now.first > r )
      continue;
    else if ( now.first >= l ) {
      if ( now.first + now.second.size() - 1 <= r ) {
        flag = 1;
        break;
      } else {
        uint64_t n = now.second.size();
        assert( r - now.first + 1 <= now.second.size() );
        now.second = now.second.substr( r - now.first + 1, n - ( r - now.first + 1 ) );
        now.first = r + 1;
      }
    } else {
      pair<uint64_t, string> res;
      res.first = now.first;
      res.second = now.second.substr( 0, min( l - now.first, now.second.size() ) );
      temp.push_back( res );
      if ( now.first + now.second.size() - 1 > r ) {
        uint64_t n = now.second.size();
        assert( r - now.first + 1 <= now.second.size() );
        now.second = now.second.substr( r - now.first + 1, n - ( r - now.first + 1 ) );
        now.first = r + 1;
      } else {
        flag = 1;
        break;
      }
    }
  }
  if ( !flag )
    temp.push_back( now );
  // inserting temp
  size_t pos = 0;
  for ( size_t i = 0; i < temp.size(); i++ ) {
    int flg = 0;
    while ( pos < buffer.size() ) {
      if ( temp[i].first < buffer[pos].first ) {
        buffer.insert( buffer.begin() + pos, temp[i] );
        stored += temp[i].second.size();
        flg = 1;
        break;
      } else
        pos++;
    }
    if ( !flg ) {
      buffer.push_back( temp[i] );
      stored += temp[i].second.size();
    }
  }
  // pushing
  for ( size_t i = 0; i < buffer.size() - 1; i++ ) {
    if ( ( buffer[i].first > buffer[i + 1].first ) && buffer.size() == 3 )
      assert( 0 );
  }
  for ( size_t i = 0; i < buffer.size(); i++ ) {
    if ( expected == buffer[i].first ) {
      output_.writer().push( buffer[i].second );
      expected += buffer[i].second.size();
      stored -= buffer[i].second.size();
    } else
      break;
  }
  while ( buffer.size() > 0 && buffer[0].first <= expected )
    buffer.erase( buffer.begin() );
  if ( eof_index != 1145141919810 && eof_index == expected )
    output_.writer().close();
}

uint64_t Reassembler::bytes_pending() const
{
  // Your code here.
  return stored;
}
