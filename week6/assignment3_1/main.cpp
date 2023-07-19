/* Exercise 1
 * Create a class that can only be instantiated by static 
 * member functions.  (i.e. a class that has a static member 
 * function that returns an object of the type of the class itself)
 * 
 * Exercise 2
 * Create class declarations for animal, bird, wings, eyes, 
 * parrot and dog.  Use inheritance to show relations between the classes.
 * 
 * Exercise 3
 * Play around the classes of ex2. a bit.
 * Create a constructor and destructor for each of the classes, 
 * where you print out what happens e.g. ("created an animal", 
 * "destroyed eyes", yes, that sounds weird, feel free to write something
 * else as long as you know what is happening.)  
 * Try out what happens when you instantiate different classes.
 * Create function with the same name inside base and derived classes.  
 * Try out how the calls work from different clases.*/

#include "includes/classes.hpp"

int main() {
    // EXERCISE 1
    Exercise1_class ex = Exercise1_class::create_instance();
    ex.print_dummy();

    // EXERCISE 3
    //Animal animal;
    Bird bird;
    //Wings wings;
    //Eyes eyes;
    Parrot parrot;
    //Dog dog;
    bird.print_info();
    parrot.print_info();

    return 0;
}

