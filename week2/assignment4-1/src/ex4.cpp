#include "../includes/ex4.h"

void write_number_of_characters(std::ifstream& file_name) {
    int counter{};
    std::string line{};
    // Read how many charactes are in the each line and count them
    while (getline(file_name, line)) {
        counter += line.length();
    }
    file_name.close();  // Close input file
    std::cout << counter << " characters found!\n";
}