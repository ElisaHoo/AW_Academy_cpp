#include "includes/creature.hpp"

int main() {
    Creature human('E');
    Creature robo(102);
    Creature alien(588.123f);
    Creature creature;  // Default constructor makes human type
    std::string check_type{creature.check_creature_type()};
    std::cout << "'creature' -objects's type is: " << check_type << "\n";
    std::cout << "Alien's id-value is: " << alien.return_alien_identifier() << "\n"; 
    return 0;
}