#include "wrapping_integers.hh"

using namespace std;

Wrap32 Wrap32::wrap( uint64_t n, Wrap32 zero_point )
{
  // Your code here.
  return zero_point + (uint32_t)( n % ( 1ll << 32 ) );
}

uint64_t Wrap32::unwrap( Wrap32 zero_point, uint64_t checkpoint ) const
{
  // Your code here.
  uint32_t tmp = raw_value_ - zero_point.raw_value_;
  uint64_t tmp1 = tmp;
  if ( checkpoint < tmp1 )
    return tmp1;
  else {
    uint64_t cnt = ( checkpoint - tmp1 ) / ( 1ll << 32 );
    uint64_t ans1 = tmp1 + cnt * ( 1ll << 32 ), ans2 = tmp1 + ( cnt + 1 ) * ( 1ll << 32 );
    if ( ans2 - checkpoint < checkpoint - ans1 )
      return ans2;
    else
      return ans1;
  }
}
