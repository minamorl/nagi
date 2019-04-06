#pragma once

#include <string>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace nagi {

namespace asio = boost::asio;
using asio::ip::tcp;

class server {
  asio::io_service& io_service_;
  tcp::acceptor acceptor_;
  tcp::socket socket_;
  int port_;

public:
  server(asio::io_service& io_service, int port);
  void start_accept();
private:
  void on_accept(const boost::system::error_code& error);
};
} // nagi
