#include <bitset>
#include <vector>

#include <nagi/hpack/decoder.hpp>
#include <nagi/hpack/constants.hpp>

namespace nagi::hpack {

using bytes = std::vector<uint8_t>;

uint32_t convert_bits_to_int(bytes const& s, int const& first, int const& length) {
    uint32_t result = 0;
    int byte_pos = first / 8;
    if (static_cast<size_t>(byte_pos) >= s.size()) {
    //    byte_pos = s.size() - 1;
    }
    int const mod = (first + length) % 8;
    int const last_byte_pos = (first + length) / 8;
    result = (s.at(byte_pos) << mod);
    ++byte_pos;
    for (; byte_pos < last_byte_pos; --byte_pos) {
        result += s.at(byte_pos) << 8 * byte_pos;
    }
    result += s.at(last_byte_pos) >> (8 - mod);
    
    return result;
}
// std::string huffman::decode(bytes str) {
//     // constants::HUFFMAN_CODE_TABLE;
//     std::string result;
//     for (auto&& x : str) {
        
//     }
//     return result;
// }

} // nagi::hpack