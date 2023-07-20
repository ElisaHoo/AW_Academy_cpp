#include "../includes/ex3.hpp"

Creature::Creature() {
    human_id = 'A';
    type = Type::human;
    assert((isalpha(human_id)) && "human_type should be character!");
    std::cout << "No argument was given, so a human-type creature was "
                 "created with id-value 'A'\n";
    }

Creature::Creature(const char human_type) {
    human_id = human_type;
    type = Type::human;
}

Creature::Creature(const int robot_type) {
    robot_id = robot_type;
    type = Type::robot;
}

Creature::Creature(const float alien_type) {
    alien_id = alien_type;
    type = Type::alien;
}

std::string Creature::check_creature_type() {
    switch (type)
    {
    case Type::human:
        {
            return "human";
        }
    case Type::robot:
        {
            return "robot";
        }
    case Type::alien:
        {
            return "alien";
        }
    }
    return "The type is not defined\n";  // Which shouldn't be possible...
}

char Creature::return_human_identifier() const{
    if (type != Type::human) {
        throw std::runtime_error(
            "You tried to use 'return_human_identifier()' -function to non-human-type object"
        );
    }
    return human_id;
}

int Creature::return_robot_identifier() const{
    if (type != Type::robot) {
        throw std::runtime_error(
            "You tried to use 'return_robot_identifier()' -function to non-robot-type object"
        );
    }
    return robot_id;
}

float Creature::return_alien_identifier() const{
    if (type != Type::alien) {
        throw std::runtime_error(
            "You tried to use 'return_alien_identifier()' -function to non-alien-type object"
        );
    }
    return alien_id;
}