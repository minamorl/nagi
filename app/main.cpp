#include <iostream>
#include <boost/version.hpp>
#include <string>

#include "nagi/hello.hpp"

int main() {
  using namespace std::string_literals;

  std::cout << BOOST_VERSION << std::endl;
  auto s = "hello world"s;
  nagi::hello(s);

  return 0;
}
