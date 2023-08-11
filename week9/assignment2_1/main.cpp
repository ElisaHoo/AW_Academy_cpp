#include "bit.hpp"

int main() {
    // EXERCISE 1
    uint8_t value{9};
    int nth_index1{0};
    int nth_index2{1};
    int nth_index3{3};
    is_nth_bit_set(value, nth_index1);  // set
    is_nth_bit_set(value, nth_index2);  // not set
    is_nth_bit_set(value, nth_index3);  // set
    std::cout << "\n";

    // EXERCISE 2
    uint16_t value_2byte{0x0A09};
    uint32_t value_4byte{0x23C9F0};
    uint64_t value_8byte{0x8BCCD3B7};

    std::cout << "Hex before swap: 0x" << std::hex << value_2byte << "\n";
    swap_byte_order(value_2byte);
    std::cout << "Hex before swap: 0x" << std::hex << value_4byte << "\n";
    swap_byte_order(value_4byte);
    std::cout << "Hex before swap: 0x" << std::hex << value_8byte << "\n";
    swap_byte_order(value_8byte);

    // EXERCISE 3
    print_characteristics(0b10110011);  // fuzzy, large, teeth, eat, spider
    std::cout << "\n";

    // EXERCISE 4
    print_combinations(0b1001);  // puppy
    print_combinations(0b110000);  // shark
    print_combinations(0b10000010);  // giant spider
    print_combinations(0b111111);  // puppy, shark, zombie

    // EXERCISE 5
    std::string input{};
    while (true) {
        std::cout << "\nPlease enter a string with max length of 8 characters: ";
        std::getline(std::cin, input);
            if (input.size() > 8 || input.size() < 1) {
                std::cout << "The length of the string must be 1-8 characters!\n";
            } else {
                break;
            }
    }
    print_bits(input);  // e.g 56,567,8 will be 0b00100010

    return 0;
}