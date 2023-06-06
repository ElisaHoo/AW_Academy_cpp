#include <string>
#include <iostream>

/*
 * A function reverseString() that takes a string as input
 * and returns the reverse of that string
 */
void reverse_string(std::string input);

int main() {
    std::cout << "Please enter a string: ";
    std::string input{};
    std::cin >> input;

    reverse_string(input);
    return 0;
}

void reverse_string(std::string input) {
    // Print the input backwards character by character
    for (int i = input.length() - 1; i >=0 ; i--) {
        std::cout << input[i];
    }
    std::cout << "\n";
}