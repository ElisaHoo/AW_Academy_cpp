#ifndef EX1_HPP
#define EX1_HPP
#include <iostream>
#include <vector>

template <typename T, typename... Ts>
void check_arguments_match_to_specifiers(std::vector<char> specifiers, T first, Ts... rest) {   
    switch (specifiers[0])
    {
        case 'i': 
            {
                if (std::is_same_v<T, int>) {
                    // Erase the first element to get a new one for the next round
                    specifiers.erase(specifiers.begin()); 
                    break;
                } else {
                    throw std::runtime_error("The arguments and printf format specifiers do not match!");
                }
            }
        case 'f':
            {
                if (std::is_same_v<T, float>) {
                    specifiers.erase(specifiers.begin());
                    break;
                } else {
                    throw std::runtime_error("The arguments and printf format specifiers do not match!");
                }
            }
        case 'c':
            {
                if (std::is_same_v<T, char>) {
                    specifiers.erase(specifiers.begin());
                    break;
                } else {
                    throw std::runtime_error("The arguments and printf format specifiers do not match!");
                }
            }
        case 's':
            {   
                if (std::is_same_v<T, std::string>) {
                    specifiers.erase(specifiers.begin()); 
                    break;
                } else {
                    throw std::runtime_error("The arguments and printf format specifiers do not match!");
                }
            }
        default:
            { 
                throw std::runtime_error("Format specifier is unknown. This function checks only \%c, \%s, \%i and \%f specifiers");
            }
    }
    if constexpr(sizeof...(rest) > 0) {
        return check_arguments_match_to_specifiers(specifiers, rest...);
    } 
}

std::vector<char> get_specifiers(std::string fmt) {
    int index{0};
    std::vector<char> specifiers{};
    for (int i = 0; i < fmt.size(); i++) {
        if (fmt[i] == '%') {
            specifiers.push_back(fmt[i+1]);  // push a letter after the % sign to vec
        }
    }
    return specifiers;
}

template <typename ...Ts>
void safe_printf(const std::string& fmt, Ts... args) {
    std::vector<char> specifiers{get_specifiers(fmt)};  // get specifiers to vector
    // Function throws error if incorrect argument type
    check_arguments_match_to_specifiers(specifiers, args...);
    // If the check went through, print message to user
    std::cout << "Yippee! All the arguments given to printf are correct type!\n";
}

#endif