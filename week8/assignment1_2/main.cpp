/* In our animal exercise, we couldn't create a vector of our animal objects.  
 * Now, with smart pointers we have tools to make this happen.
 * Manually create a text file that contains comma-separated an animal type 
 * (species) and it's name in every line.  e.g.
 * parrot, Joe
 * dog, Lassie
 * cat, Lucifer
 * 
 * Exercise 1
 * Create a vector of unique_ptrs to animal base class, and read the file and 
 * add the animals to the vector.  If the animal species matches a class for 
 * the species, create a pointer to that type of animal, otherwise create 
 * a general animal pointer.  (You probably will need to use either 
 * `emplace_back()` or `std::move()` here.
 * Test your program by printing the contents of the vector.
 * Think about why this needed to be done with virtual classes instead of 
 * using static polymorphism, and about the tradeoffs compared to using 
 * e.g. tagged union here. */

#include "animal.hpp"


int main() {
    // EXERCISE 1
    std::vector<std::unique_ptr<Animal>> animals{add_animalptrs_to_vector("animals.csv")};
    for (auto& animal: animals) {
        animal->make_sound();
    }

    return 0;
}