#ifndef FILE_HPP
#define FILE_HPP
#include <iostream>
#include <cstdio>
#include <cstdlib>

class Cfile_handler {
    public:
        // file pointer variable to store the value returned by fopen
        FILE* file_handle;
        Cfile_handler() = default;
        Cfile_handler(std::string filename);
        std::string read_file () const; 
        const int file_size() const;
        ~Cfile_handler() {  // Destructor for releasing resource
            fclose(file_handle);
        }
};

#endif