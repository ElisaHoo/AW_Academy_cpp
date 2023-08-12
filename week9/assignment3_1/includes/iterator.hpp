#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include <string>

class Codepoint_it {
    public:
        using value_type        = char32_t;  // The type the iterator iterates over
        using pointer           = char32_t*;
        using reference         = char32_t&;

        // Conversion constructor
        Codepoint_it(std::string::iterator str_it) {
            // The iterator (=str_it) should be changed to a pointer like it_ptr 
            // (because a iterator isn't (always) a pointer like in this case)
            it_ptr = &(*str_it);
        }

        // If the leftmost bit is not set (it has value below 128), it must be a one byte long
        // ASCII character. Otherwise a bit pattern may begin with '110' (=two byte code),
        // '1110' (=three byte), '11110' (= four byte)
        const unsigned char first_bit_mask = 128; // 1000000
        const unsigned char second_bit_mask = 64; // 0100000
        const unsigned char third_bit_mask = 32; // 0010000
        const unsigned char fourth_bit_mask = 16; // 0001000
        //const unsigned char fifth_bit_mask = 8; // 0000100

        // Increment operator, to move iterator one full code point forward
        Codepoint_it& operator++();

        // dereference operator, to get the value iterator points to
        char32_t operator*() const;

        bool operator!=(const Codepoint_it&) const = default;

        bool operator==(const Codepoint_it&) const = default;
        
    private:
        // "A pointer to character" -type, where iterator is currently pointing
        std::string::pointer it_ptr;
};

#endif