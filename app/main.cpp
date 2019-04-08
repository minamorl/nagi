#include <iostream>
#include <boost/asio.hpp>
#include <string>

#include "nagi/server.hpp"

int main() {
    try {
        boost::asio::io_context io_context;
        nagi::server server(io_context, 30000);
        server.start_accept();
        io_context.run();
    }
    catch (std::exception& e) {
       std::cerr << e.what() << std::endl;
    }
  return 0;
}
