#include <sys/socket.h>
#include <netdb.h>
#include <assert.h>
#include <random>
#include <iostream>
#include <string>
#include "socket_type.hh"
#include "system_runner.hh"
#include "timestamp.hh"
#include "util.hh"
#include "config.h"

std::string generate_rand_host( void ) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> alpha_index(0, 25);

  std::string host;
  for (uint32_t j = 0; j < 4; j++) {
    for (uint32_t i = 0; i < 8; i++) {
      host.append(1,'a' +  alpha_index(gen));
    }
    host.append(1, '.');
  }
  host.erase(host.size() - 1); /* Remove the last dot */
  return host;
}

int main() {
  /* Generate a random alphabetical string */
  std::string random_host = generate_rand_host();

  /* Make DNS query */
  addrinfo *result;
  /* give hints to resolver */
  addrinfo hints;
  zero( hints );
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  uint64_t start_ms = timestamp();
  int error = getaddrinfo(random_host.c_str(), nullptr, nullptr, &result);
  uint64_t stop_ms  = timestamp();
  assert( error != 0 ); /* Must error out */

  /* ping 10 times */
  run( {PING, "-c", "10", "128.30.77.36"} );

  std::cout<<"Failed DNS took "<<(stop_ms - start_ms)<<" ms\n";

  run( {"/bin/echo", "hi"});
}
