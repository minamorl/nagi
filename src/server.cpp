#include <string>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "nagi/server.hpp"

namespace nagi {

namespace asio = boost::asio;
using asio::ip::tcp;

server::server(asio::io_service& io_service, int port)
    : io_service_(io_service),
      acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
      socket_(io_service),
      port_(port) {}

void server::start_accept()
{
  acceptor_.async_accept(
    socket_,
    boost::bind(&server::on_accept, this, asio::placeholders::error)
  );
}

void server::on_accept(const boost::system::error_code& error)
{
  if (error) {
    std::cout << "accept failed: " << error.message() << std::endl;
  }
  else {
    std::cout << "accept correct!" << std::endl;
  }
}

} // nagi
