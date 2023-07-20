#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <iostream>
#include <cassert>

// Stores type of an object
enum class Type {
    robot,
    human,
    alien
};

struct Creature
{
    // Default constructor makes human-type if user don't give any arguments
    Creature();
    // Own constructors for different types
    Creature(const char human_type);
    Creature(const int robot_type);
    Creature(const float alien_type);
    // Stores creature's id
    union {
        char human_id;  // first letter of the name
        int robot_id;  // id-number
        float alien_id;  // approx wavelength of the light alien's eyes emit
    };
    Type type;
    // To check what type is stored to object
    std::string check_creature_type();
    // To get the value/id of the stored type
    char return_human_identifier() const;
    int return_robot_identifier() const;
    float return_alien_identifier() const;
};

#endif