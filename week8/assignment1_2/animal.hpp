#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <type_traits>

class Animal {

    public:
        std::string name{};
        Animal() {
            name = "unknown";
        } 
        Animal(std::string animal_name) {
            name = animal_name;
        }
        virtual void make_sound() {
            std::cout << name << " says: \"???\"\n";
        }
        virtual bool has_beak() const {return false;}
        virtual bool has_teeth() const {return false;}
        virtual ~Animal() = default;

    private:
};

class Lion : public Animal {

    public:
        // Default name constructor
        Lion() {
            Animal::name = "Simba";
        } 
        Lion(std::string animal_name) {
            Animal::name = animal_name;
        }
        void make_sound() override {
            std::cout << Animal::name << " says: \"ROAR!\"\n";
        }
        virtual bool has_teeth() const override {return true;}
        virtual ~Lion() = default;

    private:
};

class Parrot : public Animal {

    public:
        Parrot() {
            Animal::name = "Polly";
        }
        Parrot(std::string animal_name) {
            Animal::name = animal_name;
        }
        void make_sound() override {
            std::cout << Animal::name << " says: \"Hello world!\"\n";
        }
        virtual bool has_beak() const override {return true;}
        virtual ~Parrot() = default;

    private:

};

void sound(Animal& animal) {
    animal.make_sound();
}


std::vector<std::unique_ptr<Animal>> add_animalptrs_to_vector(std::string filename) {
    std::ifstream file_to_read(filename);
    if (!file_to_read.is_open()) {
        throw std::runtime_error("Error reading the file");
    }
    std::string type;
    std::string name;
    std::vector<std::unique_ptr<Animal>> animal_obj_vect;
    while (file_to_read >> type >> name) {
        // Remove comma
        type.erase(remove(type.begin(), type.end(), ','), type.end());
        if (type == "lion") {
            // 1st solution:
            // the vector directly receives the rvalue reference
            animal_obj_vect.emplace_back(std::make_unique<Lion>(name));
        } else if (type == "parrot") {
            // 2nd solution:
            // parrot_ptr has to be changed rvalue reference
            std::unique_ptr<Parrot> parrot_ptr = std::make_unique<Parrot>(name);
            //std::cout << std::boolalpha << std::is_rvalue<decltype(parrot_ptr)>::value << "\n";
            animal_obj_vect.emplace_back(std::move(parrot_ptr));
        } else {
            std::unique_ptr<Animal> animal_ptr = std::make_unique<Animal>(name);
            animal_obj_vect.emplace_back(std::move(animal_ptr));
        }
    }
    return animal_obj_vect;
}

#endif