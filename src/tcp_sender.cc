#include "tcp_sender.hh"
#include "tcp_config.hh"
#include <assert.h>

using namespace std;

uint64_t TCPSender::sequence_numbers_in_flight() const
{
  uint64_t sum = 0;
  for ( size_t i = 0; i < inflight.size(); i++ ) {
    sum += inflight[i].sequence_length();
  }
  return sum;
}
uint64_t TCPSender::consecutive_retransmissions() const
{
  return retransmission;
}

void TCPSender::push( const TransmitFunction& transmit )
{
  uint64_t win_siz = ( windowsize == 0 ) ? 1 : windowsize;
  while ( sequence_numbers_in_flight() < win_siz ) {
    TCPSenderMessage res;
    if ( input_.has_error() )
      res.RST = 1;
    uint64_t sent_tmp = sent;
    if ( !syn_set )
      syn_set = 1, res.SYN = 1, outgoing++, sent++;
    string tmp = std::string( input_.reader().peek() );
    uint64_t len = min( win_siz - outgoing, min( tmp.size(), TCPConfig::MAX_PAYLOAD_SIZE ) );
    string ret = tmp.substr( 0, len );
    input_.reader().pop( len );
    outgoing += len;
    sent += len;
    Wrap32 seqno = Wrap32::wrap( sent_tmp, isn_ );
    res.payload = ret;
    res.seqno = seqno;
    string tmp1 = std::string( input_.reader().peek() );
    if ( !fin_set && ( writer().is_closed() ) && outgoing < win_siz && tmp1.size() == 0 )
      fin_set = 1, res.FIN = 1, outgoing++, sent++;
    if ( !res.sequence_length() )
      break;
    transmit( res );
    if ( !intime )
      intime = 1, total_time = 0;
    int flag = 0;
    for ( size_t i = 0; i < inflight.size(); i++ ) {
      uint64_t val2 = inflight[i].seqno.unwrap( isn_, sent );
      if ( val2 > sent_tmp ) {
        auto it = inflight.begin() + i;
        inflight.insert( it + i, res );
        flag = 1;
        break;
      }
    }
    if ( !flag )
      inflight.push_back( res );
    if ( tmp1.size() == 0 || reader().is_finished() )
      break;
  }
}

TCPSenderMessage TCPSender::make_empty_message() const
{
  TCPSenderMessage res;
  Wrap32 seqno = Wrap32::wrap( sent, isn_ );
  res.seqno = seqno;
  if ( input_.has_error() )
    res.RST = 1;
  return res;
}

void TCPSender::receive( const TCPReceiverMessage& msg )
{
  uint64_t tmp1 = sequence_numbers_in_flight();
  if ( !msg.ackno.has_value() ) {
    if ( msg.window_size == 0 )
      input_.set_error();
  }
  if ( msg.ackno.has_value() ) {
    uint64_t val1 = msg.ackno.value().unwrap( isn_, sent );
    if ( inflight.size() > 0 ) {
      uint64_t val3 = inflight[0].seqno.unwrap( isn_, sent );
      if ( val3 < val1 ) {
        auto it = inflight.begin();
        int flag = 0;
        for ( size_t i = 0; i < inflight.size(); i++ ) {
          uint64_t val2 = inflight[i].seqno.unwrap( isn_, sent );
          if ( val2 >= val1 && i != 0 ) {
            auto now = inflight.begin() + i;
            if ( val1 != val2 )
              now--;
            inflight.erase( it, now );
            flag = 1;
            break;
          }
        }
        if ( !flag ) {
          uint64_t val2 = inflight[inflight.size() - 1].seqno.unwrap( isn_, sent );
          if ( val2 < val1 && ( inflight[inflight.size() - 1].sequence_length() + val2 == val1 ) )
            inflight.clear();
          else if ( val2 < val1 && ( inflight[inflight.size() - 1].sequence_length() + val2 > val1 ) ) {
            TCPSenderMessage mid = inflight[inflight.size() - 1];
            inflight.clear();
            inflight.push_back( mid );
          }
        }
      }
    }
  }
  windowsize = msg.window_size;
  outgoing = sequence_numbers_in_flight();
  if ( tmp1 != outgoing ) {
    cur_rto = initial_RTO_ms_;
    retransmission = 0;
    if ( outgoing != 0 )
      total_time = 0;
  }
  if ( !inflight.size() )
    intime = 0, total_time = 0;
}
void TCPSender::tick( uint64_t ms_since_last_tick, const TransmitFunction& transmit )
{
  if ( !intime )
    return;
  total_time += ms_since_last_tick;
  if ( total_time >= cur_rto && inflight.size() > 0 ) {
    auto fst = inflight.begin();
    transmit( *fst );
    if ( windowsize > 0 ) {
      cur_rto *= 2;
      retransmission++;
    }
    total_time = 0;
  }
}
