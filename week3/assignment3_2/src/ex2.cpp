#include "../includes/ex2.h"

std::string convert_to_uppercase(std::string str) {
    std::transform(str.cbegin(), str.cend(), str.begin(), [](unsigned char c) {return std::toupper(c);});
    return str;
}

std::string convert_to_lowercase(std::string str) {
    std::transform(str.cbegin(), str.cend(), str.begin(), [](unsigned char c) {return std::tolower(c);});
    return str;
}

bool check_if_palindrome(std::string str) {
    std::string backward = str;  // stores the reverse of the string
    std::reverse(backward.begin(), backward.end());
    return (backward == str);

}