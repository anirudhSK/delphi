#include <random>
#include <iostream>
#include <string>
#include "system_runner.hh"

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
  std::cout<<generate_rand_host()<<"\n";

  run( {"/bin/echo", "hi"});
}
