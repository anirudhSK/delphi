#ifndef PROBER_HH_
#define PROBER_HH_

#include <string>
#include "address.hh"
#include "socket.hh"

class Prober {
 public:
  Prober(const Address  & t_probe_server,
         const uint16_t & t_num_trains,
         const uint16_t & t_train_size);
  void send_probes( void );

 private:
  void send_packet_train( uint16_t train_size );
  std::string get_nonce( void );
  Address probe_server_;
  Socket probe_socket_;
  const uint16_t num_trains_;
  const uint16_t train_size_;
};

#endif //  PROBER_HH_
