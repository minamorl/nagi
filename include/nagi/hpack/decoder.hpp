#pragma once

#include <vector>
#include <string>

namespace nagi::hpack {

using bytes = std::vector<uint8_t>;

class huffman {
public:
    std::string decode(bytes str);
};

} // nagi::hpack