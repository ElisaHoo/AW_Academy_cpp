/* Let's return once more to the Object class we started on monday.
 * Exercise 1
 * Overload the << operator for the class so you can directly output it's contents
 * with std::cout
 * 
 * Exercise 2
 * Create a function (think about where you should put this) that reads in a string,
 * checks its contents and creates Object type from the contents.  (So if it the string
 * represents an integer, the Object should contain integer, if it is a string/char, 
 * it should be initial, etc.)
 * You can use following functions to check if the string is a float or an integer, 
 * they require the header <charconv>
 * 
 * Exercise 3
 * Using the TextFile class we created previously, create a function that reads a text 
 * file line by line and creates an Object for each line and stores them in a container.
 * 
 * Exercise 4
 * Combine what we have to create a program that reads in a text file, creates 
 * the Objects and then prints out the elements found in the container.
 */

#include "includes/ex.hpp"

int main() {
    // EXERCISE 1 & 2
    Supernatural::Creature creature(3);
    std::cout << "Type is " << creature.check_type();

    Supernatural::Creature creature2{Supernatural::Creature::create_creature("R")};
    std::cout << creature2.return_human_identifier() << "\n";

    Supernatural::Creature creature3{Supernatural::Creature::create_creature("458.7")};
    std::cout << creature3.return_alien_identifier() << "\n";

    Supernatural::Creature creature4{Supernatural::Creature::create_creature("3")};
    std::cout << creature4.return_robot_identifier() << "\n";

    Supernatural::Creature creature5{Supernatural::Creature::create_creature("Anna-Liisa")};
    std::cout << creature5.return_human_identifier() << "\n";

    // FAILS because name includes & -sign
    //Supernatural::Creature creature6{Supernatural::Creature::create_creature("Elisa&")};
    //std::cout << creature6.return_human_identifier() << "\n";

    // EXERCISE 3 & 4
    Supernatural::Create_from_file creatures("creatures.txt");
    std::cout << "Creatures in the file are:\n" << creatures << "\n";
}