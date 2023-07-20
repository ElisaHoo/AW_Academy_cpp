/* Exercise 1
 * Returning to the earlier text file class, use encapsulation to 
 * hide the implementation details.
 * Split the implementation and declarations into source and header file(s).  
 * Pay attention to the headers you need to include in each.
 * 
 * Exercise 2
 * A friend function is a function that has access to the internals (private members)
 * of a type.  You can declare such inside a class using friend keyword.
 * Make the functions to add and substract work with the encapsulated version of
 * the positive integer class (6.2.1).
 * Exercise 3
 * Do the same for the Object class (6.1.2) we created earlier. */

#include "includes/ex1.hpp"
#include "includes/ex2.hpp"
#include "includes/ex3.hpp"

int main() {
    // EXERCISE 1
    Cfile_handler fhandler("lorem.txt");
    std::string line{fhandler.read_file()};
    std::cout << line << "\n";

    // EXERCISE 2
    Positive_integer posi1{3};
    Positive_integer posi2{2};
    Positive_integer posi3{multiply(posi1, posi2)};
    std::cout << "3 * 2 = ";
    posi3.print_number();

    // EXERCISE 3
    Creature human('E');
    Creature robo(102);
    Creature alien(588.123f);
    Creature creature;  // Default constructor makes human type
    std::string check_type{creature.check_creature_type()};
    std::cout << "'creature' -objects's type is: " << check_type << "\n";
    std::cout << "Alien's id-value is: " << alien.return_alien_identifier() << "\n"; 

    return 0;
}