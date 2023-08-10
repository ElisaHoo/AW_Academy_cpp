#include "includes/optional.hpp"
#include "includes/exp.hpp"

int main() {
    // EXERCISE 1
    if (auto succeeds = Opt::create_instance(true)) {
        std::cout << "Class Opt -instance created!\n";
    }
    if (auto fails = Opt::create_instance(false)) {
        std::cout << "nullopt!\n";  // Does not print this
    }

    // EXERCISE 2
    if (auto succeeds = Exp::create_instance(true)) {
        std::cout << "Class Exp -instance created!\n";
    }
    if (auto fails = Opt::create_instance(false)) {
        std::cout << "Error!\n";  // Does not print this
    }

    return 0;
}