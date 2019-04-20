#pragma once

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "nagi/tcp_connection.hpp"

namespace nagi {

class server {
    boost::asio::io_context& io_context_;
    boost::asio::ip::tcp::acceptor acceptor_;
    int port_;

public:
    server(boost::asio::io_context& io_context, int port);
    void start_accept();
private:
    void on_accept(tcp_connection::pointer new_connection,
        const boost::system::error_code& error);
};

} // nagi