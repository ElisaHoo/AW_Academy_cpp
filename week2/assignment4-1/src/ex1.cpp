#include "../includes/ex1.h"

void take_filename_and_print_content(std::ifstream& file_name) {
    std::string line{};
    // Reads the whole line even though there are whitespaces etc
    while (getline(file_name, line)) {
        std::cout << line << "\n";
    }
    file_name.close();
}