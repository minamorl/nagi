#include <iostream>
#include <boost/version.hpp>
#include <string>

#include "nagi/hello.hpp"

int main() {
  std::cout << BOOST_VERSION << std::endl;
  nagi::hello("hello world");

  return 0;
}
