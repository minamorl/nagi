#include <string>
#include <iostream>
#include "nagi/hello.hpp"

namespace nagi {

void hello(const std::string& s) {
  std::cout << s << std::endl;
}

} // nagi
