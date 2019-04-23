#pragma once

#include <vector>
#include <string>

namespace nagi::hpack {

class huffman {
public:
    std::vector<std::string> decode(std::vector<uint8_t>);
};

} // nagi::hpack