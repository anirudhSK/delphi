#include <unistd.h>
#include <random>
#include "prober.hh"
#include "socket_type.hh"

using namespace std;

Prober::Prober(const Address  & t_probe_server,
               const uint16_t & t_num_trains,
               const uint16_t & t_train_size)
    : probe_server_( t_probe_server ),
      probe_socket_( UDP ),
      num_trains_( t_num_trains ),
      train_size_( t_train_size )
{}

void Prober::send_probes( void ) {
  for (uint16_t i = 0; i < num_trains_; i++) {
    printf("Sending packet train %u\n", i);
    send_packet_train(train_size_);
    usleep(20000); /* Sleep 20 ms or 20000 us */
  }
}

void Prober::send_packet_train( uint16_t train_size ) {
  auto nonce = get_nonce();
  for (uint16_t i = 0; i < train_size; i++) {
    probe_socket_.sendto(probe_server_, nonce + std::string(990, 'x'));
  }
}

string Prober::get_nonce( void ) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> alpha_index(0, 255);

  /* 10-byte nonce */
  std::string nonce;
  for (uint32_t i = 0; i < 10; i++) {
    nonce.append(1, alpha_index(gen));
  }
  return nonce;
}
