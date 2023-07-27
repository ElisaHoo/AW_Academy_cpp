#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <vector>

class Animal {
    
    public:
        std::string name{};
        Animal() : name{""} {} 
        virtual void make_sound() = 0;  // Pure virtual when '= 0';
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

#endif