#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <cassert>
#include <cmath>
#include <sstream>
#include <iterator>

void finland() {
    std::cout << "Hello Finland!\n";
}

void europe() {
    std::cout << "Hello Europe!\n";
}

void world() {
    std::cout << "Hello world!\n";
}

int get_and_check_input() {
    std::string choice{};
    while(std::getline(std::cin, choice)) {
        if ((choice == "1" || choice == "2" || choice == "3")) {
            break;
        }
        std::cout << "Invalid input! Please enter number 1, 2 or 3.\n";    
    }
    return stoi(choice);
}

float addition(float lhs, float rhs) {
    return lhs + rhs;
}

float subtraction(float lhs, float rhs) {
    return lhs - rhs;
}

float multiplication(float lhs, float rhs) {
    return lhs * rhs;
}

float division(float lhs, float rhs) {
    assert((rhs != 0) && "You can not divide by zero");
    return (lhs / rhs);
}

std::vector<std::string> parse_input(std::string input) {
    std::istringstream iss(input);
    std::vector<std::string> container{};
    std::copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::back_inserter(container));
    return container;
}

int main() {
    // EXERCISE 1
    std::vector<std::function<void()>> greeting = {
        finland,
        europe,
        world
    };
    std::cout << "Please choose who to greet:\n";
    std::cout << "(1) Finland\n";
    std::cout << "(2) Europe\n";
    std::cout << "(3) world\n";
    greeting[get_and_check_input() - 1]();   


    // EXERCISE 2
    std::unordered_map<char, std::function<float(int lhs, int rhs)>> calculator = {
        {'a', addition},
        {'s', subtraction},
        {'m', multiplication},
        {'d', division}
    };

    std::cout << "\nMap-calculator!\n";
    std::cout << "Please, enter calculation e.g. 1+1 "
                 "(possible operators are: -, +, *, /)\n";
    std::string calculation{};
    std::getline(std::cin, calculation);

    // Parse input and place values and operator to vector
    std::vector<std::string> parsed_input{parse_input(calculation)};
    
    // Get lhs value
    float lhs{stof(parsed_input[0])};
    // Get rhs value
    float rhs{stof(parsed_input[2])};
    //Get operator
    char oper{parsed_input[1][0]};
    
    switch (oper) {
    case '+':
        {
            float result{calculator['a'](lhs, rhs)};
            std::cout << "The result is: " << result << "\n";
            break;
        }
        
    case '-':
        {
            float result{calculator['s'](lhs, rhs)};
            std::cout << "The result is: " << result << "\n";
            break;
        }

    case '*':
        {
            float result{calculator['m'](lhs, rhs)};
            std::cout << "The result is: " << result << "\n";
            break;
        }
    
    case '/':
        {
            float result{calculator['d'](lhs, rhs)};
            std::cout << "The result is: " << result << "\n";
            break;
        }

    default:
        throw std::runtime_error("Couldn't read your calcultation");
        break;
    }
    
    return 0;
}