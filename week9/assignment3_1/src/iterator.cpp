#include "../includes/iterator.hpp"

Codepoint_it& Codepoint_it::operator++() { 
            char first_byte{*it_ptr};
            std::string::difference_type offset{1}; // by default character is one byte long
            
            // Character is four byte long
            if ((first_byte & first_bit_mask) && 
                (first_byte & second_bit_mask) && 
                (first_byte & third_bit_mask) && 
                (first_bit_mask & fourth_bit_mask)) {
                    offset = 4;

            // Character is three byte long
            } else if ((first_byte & first_bit_mask) && 
                       (first_byte & second_bit_mask) &&
                       (first_byte & third_bit_mask)) {
                            offset = 3;

            // Character is two byte long
            } else if ((first_byte & first_bit_mask) &&
                       (first_byte & second_bit_mask)) {
                            offset = 2;
            }
                
            it_ptr += offset;
            return *this; 
        }

char32_t Codepoint_it::operator*() const {
            char32_t code_point{0};
            char first_byte{*it_ptr};

            // Character is four byte long
            if ((first_byte & first_bit_mask) && 
                (first_byte & second_bit_mask) && 
                (first_byte & third_bit_mask) && 
                (first_bit_mask & fourth_bit_mask)) {
                    code_point = (first_byte & 0x07) << 18;
                    char second_byte{*(it_ptr + 1)};
                    code_point += (second_byte & 0x3f) << 12;
                    char third_byte{*(it_ptr + 2)};
                    code_point += (third_byte & 0x3f) << 6;
                    char fourth_byte{*(it_ptr + 3)};
                    code_point += (fourth_byte & 0x3f);

            // Character is three byte long
            } else if ((first_byte & first_bit_mask) && 
                       (first_byte & second_bit_mask) &&
                       (first_byte & third_bit_mask)) {
                            code_point = (first_byte & 0x0f) << 12;
                            char second_byte{*(it_ptr + 1)};
                            code_point += (second_byte & 0x3f) << 6;
                            char third_byte{*(it_ptr + 2)};
                            code_point += (third_byte & 0x3f);

            // Character is two byte long
            } else if ((first_byte & first_bit_mask) &&
                       (first_byte & second_bit_mask)) {
                            code_point = (first_byte & 0x1f) << 6;
                            char second_byte{*(it_ptr + 1)};
                            code_point += (second_byte & 0x3f);
            } else {
                code_point = first_byte;
            }
            return code_point;
        }