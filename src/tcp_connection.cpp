#include "nagi/tcp_connection.hpp"

#include <string>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

namespace nagi {

using pointer = boost::shared_ptr<tcp_connection>;

pointer tcp_connection::create(boost::asio::io_context& io_context) {
    return pointer(new tcp_connection(io_context));
}

boost::asio::ip::tcp::socket& tcp_connection::socket() {
    return socket_;
}

void tcp_connection::start() {
    message_ = "Hello, world!";
    boost::asio::async_write(socket_, boost::asio::buffer(message_),
        boost::bind(&tcp_connection::handle_write, shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred)
    );
}

tcp_connection::tcp_connection(boost::asio::io_context& io_context)
    : socket_(io_context) {}

void tcp_connection::handle_write(const boost::system::error_code&, size_t)
{}

} // nagi