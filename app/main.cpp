#include <iostream>
#include <boost/asio.hpp>
#include <string>

#include "nagi/hello.hpp"

int main() {
  using namespace std::string_literals;
  boost::asio::io_service io_service;
  nagi::server server(io_service, 30000);
  server.start_accept();
  io_service.run();
  return 0;
}
