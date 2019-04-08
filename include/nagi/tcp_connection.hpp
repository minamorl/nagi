#pragma once

#include <string>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

namespace nagi {

using boost::asio::ip::tcp;

class tcp_connection
    : public boost::enable_shared_from_this<tcp_connection> {

tcp::socket socket_;
std::string message_;

public:
    using pointer = boost::shared_ptr<tcp_connection>;

    static pointer create(boost::asio::io_context& io_context);
    tcp::socket& socket();
    void start();
private:
    tcp_connection(boost::asio::io_context& io_context);
    void handle_write(const boost::system::error_code&, size_t);
};

} // nagi