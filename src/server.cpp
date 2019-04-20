#include <string>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "nagi/server.hpp"
#include "nagi/tcp_connection.hpp"

namespace nagi {

server::server(boost::asio::io_context& io_context, int port)
    : io_context_(io_context),
      acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
      port_(port) {}

void server::start_accept()
{
    tcp_connection::pointer new_connection =
        tcp_connection::create(acceptor_.get_executor().context());

    acceptor_.async_accept(
      new_connection->socket(),
      boost::bind(&server::on_accept, this, new_connection, 
        boost::asio::placeholders::error)
    );
}

void server::on_accept(tcp_connection::pointer new_connection,
    const boost::system::error_code& error)
{
    if (!error)
    {
      new_connection->start();
    }

    start_accept();
}

} // nagi
