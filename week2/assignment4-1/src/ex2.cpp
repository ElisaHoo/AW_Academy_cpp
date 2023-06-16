#include "../includes/ex2.h"

void write_number_of_lines(std::ifstream& file_name, std::ofstream& output_file) {
    int counter{0};
    std::string line{};
    // Read how many lines there are in the file and count them
    while (getline(file_name, line)) {
        counter += 1;
    }
    file_name.close();  // Close input file
    // Print the number of lines at the end of the file
    if (output_file.is_open()) {
        output_file <<  counter << "\n";
    }
    output_file.close();
}