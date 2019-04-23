#include <bitset>
#include <vector>
#include <algorithm>
#include <iterator>

#include <nagi/hpack/decoder.hpp>
#include <nagi/hpack/constants.hpp>

namespace nagi::hpack {

uint32_t convert_bits_to_int(bytes const& s, int const& first, int const& length) {
    uint32_t result = 0;
    int byte_pos = first / 8;
    if (static_cast<size_t>(byte_pos) >= s.size()) {
    //    byte_pos = s.size() - 1;
    }
    int const mod = (first + length) % 8;
    int const last_byte_pos = (first + length) / 8;
    result = s.at(byte_pos);
    ++byte_pos;
    for (; byte_pos < last_byte_pos; ++byte_pos) {
        result <<= 8;
        result += s.at(byte_pos);
    }
    result <<= mod;
    result += s.at(last_byte_pos) >> (8 - mod);
    
    return result;
}

std::string huffman::decode(bytes str) {
    std::string result;
    
    int i = 0;
    int current_huffman_length = 0;
    while (i < str.size() * 8 /* bit length */) {
        auto fi = std::find_if(std::begin(constants::HUFFMAN_CODE_TABLE), std::end(constants::HUFFMAN_CODE_TABLE), [&] (auto& x) {
            current_huffman_length = x.second;
            return x.first == convert_bits_to_int(str, i, x.second);
        });
        if (fi != std::end(constants::HUFFMAN_CODE_TABLE)) {
            i += current_huffman_length;
            result.push_back(static_cast<char>(fi->first));
        } else {
            throw std::runtime_error("Invalid huffman-encoded value are passed");
        }
    }
    return result;
}

} // nagi::hpack