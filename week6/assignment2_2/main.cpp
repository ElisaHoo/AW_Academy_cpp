/* Exercise 1
 * We are going to wrap C file functionality to a C++ class here.
 * We want a type for text files we can use to read them more easily.
 * Create a class that
 * - Using C file functionality, opens a text file when instantiated 
 *   (either with a static member function, or a constructor)
 * - Uses RAII, and cleans up after itself
 * - Has a function to read in the next line of the text file
 * - (optional) Has a function to print the file size
 * To open a file using C functionality, first #include <cstdio> and <cstdlib>
 * C uses FILE* as the type for the files.  This is a pointer, but we do not 
 * need to concern ourselves with that too much right now.*/

#include "includes/file.hpp"

int main() {
    Cfile_handler fhandler("lorem.txt");
    std::string line{fhandler.read_file()};
    std::cout << line << "\n";
    int size{fhandler.file_size()};
    std::cout << "The file size is " << size << " bytes.\n";
    return 0;
}