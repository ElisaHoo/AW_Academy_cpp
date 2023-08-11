#ifndef BIT_HPP
#define BIT_HPP
#include <iostream>
#include <type_traits>
#include <cstdint>

// EXERCISE 1
template <typename T>
void is_nth_bit_set(const T& value_to_check, int nth) {
    // Bit is set if it is 1
    // (1 << nth) creates a value that has set bit as n.th bit 
    // If bitwise AND of value_to_check and (1 <<  nth) is non-zero, result is set
    // else result is not set
    if (value_to_check & (1 << nth)) {
        std::cout << nth << ". bit is set\n";
    } else {
        std::cout << nth << ". bit is not set\n";
    }
}

// EXERCISE 2
template <typename T>
void swap_byte_order(T val) {
    static_assert(std::is_integral<T>::value, "Integral required");
    std::cout << "Size: " << sizeof(T) << " bytes\n";
    T value_after;
    // If size is 2 bytes (= short, int16_t)
    if constexpr (sizeof(T) == 2) {
        value_after = 
        // swaps FF from rhs 8 bits to left | swaps FF from lhs 8 bits to right
        ((val & 0x00FFu) << 8) | ((val & 0xFF00u) >> 8);
    // If size is 4 bytes (= int, long, int32_t)
    } else if constexpr (sizeof(T) == 4) {
        value_after = 
        ((val & 0x000000FFu) << 24) |
        ((val & 0x0000FF00u) << 8) |
        ((val & 0x00FF0000u) >> 8) |
        ((val & 0xFF000000u) >> 24);
    // If size is 8 bytes (= long long, int64_t)
    } else if constexpr (sizeof(T) == 8) {
        value_after =
        ((val & 0xFF00000000000000ull) >> 56) |
        ((val & 0x00FF000000000000ull) >> 40) |
        ((val & 0x0000FF0000000000ull) >> 24) |
        ((val & 0x000000FF00000000ull) >> 8) |
        ((val & 0x00000000FF000000ull) << 8) |
        ((val & 0x0000000000FF0000ull) << 24) |
        ((val & 0x000000000000FF00ull) << 40) |
        ((val & 0x00000000000000FFull) << 56);
    }
    std::cout << "Hex after swap 0x" << std::hex << value_after << "\n";
}

// EXERCISE 3
// If first bit is set, creature is fuzzy, if second, creature is large and so on

enum Flags {
    IS_FLUFFY           = 0b1,
    IS_LARGE            = 0b10,
    HAS_GOOGLY_EYES     = 0b100,
    IS_CUTE             = 0b1000,
    HAS_TEETH           = 0b10000,
    IS_ABOUT_TO_EAT_YOU = 0b100000,
    IS_FRIENDLY         = 0b1000000,
    IS_SPIDER           = 0b10000000,
};

void print_characteristics(uint8_t bits) {
    if (bits & Flags::IS_FLUFFY) {
        std::cout << "is fuzzy\n";
    }
    if (bits & Flags::IS_LARGE) {
        std::cout << "is large\n";
    }
    if (bits & Flags::HAS_GOOGLY_EYES) {
        std::cout << "has googly eyes\n";
    }
    if (bits & Flags::IS_CUTE) {
        std::cout << "is cute\n";
    }
    if (bits & Flags::HAS_TEETH) {
        std::cout << "has teeth\n";
    }
    if (bits & Flags::IS_ABOUT_TO_EAT_YOU) {
        std::cout << "is about to eat you\n";
    }
    if (bits & Flags::IS_FRIENDLY) {
        std::cout << "is friendly\n";
    }
    if (bits & Flags::IS_SPIDER) {
        std::cout << "is spider\n";
    }
}

void print_combinations(uint8_t bits) {
    if ((bits & Flags::IS_FLUFFY) && (bits & Flags::IS_CUTE)) {
        std::cout << "It is a puppy!\n"; 
    }
    if ((bits & Flags::HAS_TEETH) && (bits & Flags::IS_ABOUT_TO_EAT_YOU)) {
        std::cout << "It is a shark!\n";
    }
    if ((bits & Flags::IS_LARGE) && (bits & Flags::IS_SPIDER)) {
        std::cout << "It is a giant spider!\n";
    }
    if ((bits & Flags::HAS_GOOGLY_EYES) && (bits & Flags::IS_ABOUT_TO_EAT_YOU)) {
        std::cout << "It is a zombie!\n";
    }
}

void print_bits(const std::string& str) {
    uint8_t bits{0b00000000};
    int i{0};
    for (char c : str) {
        if (c == ',') {
            bits = bits | (1 << i);
        }
        ++i;
    }
    std::cout << "0b";
    for (int i = 0; i <= sizeof(uint8_t) * 8 -1; ++i) {
        std::cout << ((bits & (1 << i)) ? 1 : 0);
    }
    std::cout << "\n";
}

#endif