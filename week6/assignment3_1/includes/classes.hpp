#ifndef CLASSES_HPP
#define CLASSES_HPP
#include <iostream>

class Exercise1_class {
    public:
        static Exercise1_class create_instance();
        void print_dummy() {
            std::cout << dummy << "\n";
        }

    private:
        Exercise1_class() = default;
        std::string dummy{};
};

class Animal {
    public:
        Animal();
        ~Animal();
};

class Bird : public Animal {
    public:
        Bird();
        ~Bird();
        void print_info();
};

class Wings {
    public:
        Wings();
        ~Wings();
};

class Eyes {
    public:
        Eyes();
        ~Eyes();
};

class Parrot : public Bird {
    public:
        Parrot();
        ~Parrot();
        void print_info();
        
    private:
        Eyes eyes;
        Wings wings;
};

class Dog : public Animal {
    public:
        Dog();
        ~Dog();
        
    private:
        Eyes eyes;
};

#endif