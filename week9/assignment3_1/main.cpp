#include "includes/iterator.hpp"

int main() {
    // EXERCISE 1
    std::string str{"abcäö♫⭐"};
    for (auto character : str) {
        // Prints ä, ö and symbols like � (because they're extended ASCII codes)
        std::cout << "Character: " << character << " and character as integer: ";
        std::cout << static_cast<int>(character) << "\n";
    }
    std::cout << "\n";

    // EXERCISE 3
    /*for (Codepoint_it it = std::begin(str); it != std::end(str); ++it) {
        std::cout << *it << ": " << static_cast<int>(*it) << "\n";
    }
    */

    // EXERCISE 5
    for (Codepoint_it it = str.begin(); it != str.end(); ++it) {
        std::cout << std::hex << static_cast<int>(*it) << "\n";
    }

    return 0;
}