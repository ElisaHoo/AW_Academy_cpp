#include "includes/animal.hpp"

int main() {
    // EXERCISE 1
    std::variant<std::string, int, float> creature1{"Elisa"};
    std::variant<std::string, int, float> creature2{102};
    std::variant<std::string, int, float> creature3{455.123f};
    std::cout << "creature1 id is: " << std::get<std::string>(creature1) << "\n";
    std::cout << "creature2 id is: " << std::get<int>(creature2) << "\n";
    std::cout << "creature3 id is: " << std::get<float>(creature3) << "\n";
    
    // EXERCISE 2
    Parrot parrot;
    Lion lion;
    std::vector<anim> animals{parrot, lion};
    for (auto animal : animals) {
        std::visit([](auto&& arg){ arg.make_sound(); }, animal);
    }

    return 0;
}