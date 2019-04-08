#pragma once

#include <map>
#include <vector>

namespace nagi { namespace hpack {
struct constants {
    static const std::vector<std::pair<uint32_t, uint8_t>> HUFFMAN_CODE_TABLE;
};
} }// nagi 