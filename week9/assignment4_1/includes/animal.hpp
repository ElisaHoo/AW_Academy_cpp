#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <vector>
#include <variant>

class Lion {

    public:
        Lion() {
            name = "Simba";
        } 
        void make_sound() {
            std::cout << name << " says: \"ROAR!\"\n";
        }
        bool has_teeth() const {return true;}
        virtual ~Lion() = default;

    private:
        std::string name{};
};

class Parrot {

    public:
        Parrot() {
            name = "Polly";
        }
        void make_sound() {
            std::cout << name << " says: \"Hello world!\"\n";
        }
        bool has_beak() const {return true;}
        ~Parrot() = default;

    private:
        std::string name{};

};

using anim = std::variant<Lion, Parrot>;

#endif