// Create a new file and header for each new feature for the program.

#include "includes/ex1.h"
#include "includes/ex2.h"
#include "includes/ex3.h"
#include "includes/ex4.h"
#include "includes/ex5.h"

int main(int argc, char* argv[]) {  // argc = argument count, argv = argument value

    // Check how many command line arguments user have been entered
    if (argc < 2) {
        /* Exercise 5:
         * Add a function that can calculate the size of the text files in 
         * a (current) directory.*/
        size_of_txt_files();
    
    } else {
        // If argc is more than three, print the instructions
        if (argc > 3) {
            std::cout << "Please enter max three command line arguments including the program path first\n";
            std::cout << "After the program path, enter a txt-file name and the program will print the file "
                         "content to the console\n";
            std::cout << "You can add flags after the file name:\n"; 
            std::cout << "'-l' or '--lines' will count the lines in a file and write the number at the end "
                         "of the file\n";
            std::cout << "'-w' or '--words' will print the number of words on the console\n";
            std::cout << "'-c' or '--chars' will print the number of characters on the console\n";
            std::cout << "If you won't enter a file name or flags, the program will print the size "
                         "of txt-file(s) in a current directory\n";

        }
        std::ifstream file_name(argv[1]); //gets the filename from the command line

        if (!file_name.is_open()) {  // Checks if the file is open
        std::cout << "Couldn't open the file\n";
        }   
        
        if (argc == 2) {
        /* Exercise 1:
        * takes a file name as a command-line argument and prints the contents of 
        * the file to the console. */
        take_filename_and_print_content(file_name);
    
        } else if (argc == 3) {
            // Open output file, ios::app is to make the writing to the end of the file
            std::ofstream output_file(argv[1], std::ios::app);
            
            /* Exercise 2:
            * instead of printing the file contents, prints the number of lines in 
            * the file. */
            if ((std::string(argv[2]) == "-l") || (std::string(argv[2]) == "--lines")) {
                write_number_of_lines(file_name, output_file);  
            } 
            
            /* Exercise 3:
             * Add a word counter. Extend your program to count the number of words in 
             * the file. Add a command-line option "-w" or "--words".*/
            else if ((std::string(argv[2]) == "-w") || (std::string(argv[2]) == "--words")) {
                write_number_of_words(file_name);
            }

            /* Exercise 4:
             * Add a character counter. Add a command-line option "-c" or "--chars" 
             * to activate this feature.*/
            else if ((std::string(argv[2]) == "-c") || (std::string(argv[2]) == "--chars")) {
                write_number_of_characters(file_name);
            }
        }
    }
    
    return 0;
}