#include "../includes/ex.h"

void choose_name(std::vector<std::string> names) {
    for (const auto name : names) {
        std::cout << name << " ";
    }
    std::cout << "\nPlease choose a name and enter name's index number:";
    int index{};
    std::cin >> index;
    // There are four names in the list, check if the index is out of range
    if (index < 0 || index > 3) {
        throw std::runtime_error("Index number should be between 0 and 3!\n");
    }
    std::cout << "You picked " << names[index] << "!\n";
}