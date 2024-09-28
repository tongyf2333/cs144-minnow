#include "byte_stream.hh"
#include <assert.h>

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : buffer( "" ), closed( 0 ), capacity_( capacity ), sum( 0 ), sum1( 0 )
{}

bool Writer::is_closed() const
{
  return closed;
}

void Writer::push( string data )
{
  assert( buffer.size() <= capacity_ );
  if ( !closed && buffer.length() < capacity_ ) {
    if ( buffer.length() + data.length() <= capacity_ ) {
      buffer = buffer + data;
      sum += data.size();
    } else {
      sum += capacity_ - buffer.size();
      string aa = data.substr( 0, capacity_ - buffer.length() );
      buffer = buffer + aa;
    }
  }
  assert( buffer.length() <= capacity_ );
  return;
}

void Writer::close()
{
  closed = 1;
}

uint64_t Writer::available_capacity() const
{
  assert( buffer.size() <= capacity_ );
  return capacity_ - buffer.size();
}

uint64_t Writer::bytes_pushed() const
{
  return sum;
}

bool Reader::is_finished() const
{
  return ( closed == 1 ) && ( !buffer.length() );
}

uint64_t Reader::bytes_popped() const
{
  return sum1;
}

string_view Reader::peek() const
{
  return buffer;
}

void Reader::pop( uint64_t len )
{
  if ( len <= buffer.size() ) {
    uint64_t aa = buffer.size();
    buffer = buffer.substr( len, aa - len );
    sum1 += len;
  } else {
    sum1 += buffer.size();
    buffer = "";
  }
}

uint64_t Reader::bytes_buffered() const
{
  return buffer.size();
}
