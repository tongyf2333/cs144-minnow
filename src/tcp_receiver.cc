#include "tcp_receiver.hh"

using namespace std;

void TCPReceiver::receive( TCPSenderMessage message )
{
  // Your code here.
  if ( message.RST == 1 ) {
    rst = 1;
    reader().set_error();
  }
  if ( message.SYN == 1 && !init )
    zero = message.seqno, init = 1;
  reassembler_.insert(
    message.seqno.unwrap( zero, writer().bytes_pushed() + 1 ) - 1 + ( message.SYN ), message.payload, message.FIN );
}

TCPReceiverMessage TCPReceiver::send() const
{
  // Your code here.
  TCPReceiverMessage res;
  if ( ( rst == 1 ) || reader().has_error() )
    res.RST = 1;
  if ( writer().available_capacity() > UINT16_MAX )
    res.window_size = UINT16_MAX;
  else
    res.window_size = (uint16_t)writer().available_capacity();
  if ( init ) {
    if ( !writer().is_closed() )
      res.ackno.emplace( zero + ( writer().bytes_pushed() + 1 ) );
    else
      res.ackno.emplace( zero + ( writer().bytes_pushed() + 2 ) );
  }
  return res;
}
