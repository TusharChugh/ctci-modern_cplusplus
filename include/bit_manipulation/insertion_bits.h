#pragma once

#include <cstdint>

namespace algorithm {
    uint32_t insert_bits(uint32_t input, uint32_t bits, uint8_t start, uint8_t end) {
        uint32_t mask = 0;
        for(uint8_t num = 0; num <= end - start; ++ num) {
            mask += (1 << num);
        }
        mask = ~(mask << start);
        return ((input & mask) | (bits << start));
    }
}