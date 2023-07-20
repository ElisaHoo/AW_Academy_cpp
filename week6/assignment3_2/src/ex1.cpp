#include "../includes/ex1.hpp"

Cfile_handler::Cfile_handler(std::string filename) {
    // Convert 'string' to 'const char *' for fopen to accept it
    const char* filename_c{filename.c_str()};
    file_handle = fopen(filename_c, "a+");
    if (file_handle == NULL) {
        throw std::runtime_error(
            "Couldn't open the file. Please check that the file exists.\n"
        );
    }
}

std::string Cfile_handler::read_file() const {
    int symbol{}; // int for handling EOF and new line
    std::string content{}; // string to store the file content
    while ((symbol = std::fgetc(file_handle)) != EOF && (symbol != '\n')) {
        content += static_cast<char>(symbol);
    }
    return content;
}

const int Cfile_handler::file_size() const {
    fseek(file_handle, 0 , SEEK_END);
    int file_size = ftell(file_handle);
    return file_size;
}