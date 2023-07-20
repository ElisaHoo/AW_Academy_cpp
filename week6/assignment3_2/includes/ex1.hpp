#ifndef EX1_HPP
#define EX1_HPP
#include <iostream>
#include <cstdio>
#include <cstdlib>

class Cfile_handler {
    public:
        
        Cfile_handler() = default;
        Cfile_handler(std::string filename);
        std::string read_file () const; 
        const int file_size() const;
        ~Cfile_handler() {  // Destructor for releasing resource
            fclose(file_handle);
        }
    private:
        // file pointer variable to store the value returned by fopen
        FILE* file_handle;
};

#endif