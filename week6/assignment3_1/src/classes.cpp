#include "../includes/classes.hpp"

Exercise1_class Exercise1_class::create_instance() {
    Exercise1_class class_itself;
    class_itself.dummy = "Lorem ipsum";
    return class_itself;
}

Animal::Animal() {
    std::cout << "Animal class object is created\n";
}

Animal::~Animal() {
    std::cout << "Animal class object is destroyed\n";
}

Bird::Bird() {
    std::cout << "Bird class object is created\n";
}

Bird::~Bird() {
    std::cout << "Bird class object is destroyed\n";
}

void Bird::print_info() {
    std::cout << "Birds have feathers.\n";
}

Wings::Wings() {
    std::cout << "Wings class object is created\n";
}

Wings::~Wings() {
    std::cout << "Wings class object is destroyed\n";
}

Eyes::Eyes() {
    std::cout << "Eyes class object is created\n";
}
Eyes::~Eyes() {
    std::cout << "Eyes class object is destroyed\n";
}

Parrot::Parrot() {
    std::cout << "Parrot class object is created\n";
}

Parrot::~Parrot() {
    std::cout << "Parrot class object is destroyed\n";
}

void Parrot::print_info() {
    std::cout << "Parrots have feathers.\n";
}

Dog::Dog() {
    std::cout << "Dog class object is created\n";
}
        
Dog::~Dog() {
    std::cout << "Dog class object is destroyed\n";
}