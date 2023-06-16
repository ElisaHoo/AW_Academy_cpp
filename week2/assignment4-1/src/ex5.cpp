#include "../includes/ex5.h"


void size_of_txt_files() {
    // Get the current working directory
    std::filesystem::path current_working_directory = std::filesystem::current_path();
    // Check if the directory exists
    if (!std::filesystem::exists(current_working_directory)) {
        std::cout << "Couldn't find the directory!\n";
    }
    std::vector<float> sizes{};  // vector for collecting the filesizes
    // Pick only the sizes of txt-files and push them to the vector
    for (const auto& entry : std::filesystem::directory_iterator(current_working_directory)) {
        if (entry.path().extension().string() == ".txt") {
            sizes.push_back(entry.file_size());
        }
    }
    std::cout << "The size of the text files: " << std::accumulate(sizes.begin(), sizes.end(), 0.0) << "\n";
}