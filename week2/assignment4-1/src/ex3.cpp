#include "../includes/ex3.h"

void write_number_of_words(std::ifstream& file_name) {
    int counter{};
    // Read how many words thre are in the file and count them
    for (std::string word{}; file_name >> word; ++counter) {}
    file_name.close();
    std::cout << counter << " words found!\n";
}