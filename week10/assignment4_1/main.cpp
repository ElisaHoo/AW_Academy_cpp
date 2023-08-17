#include <fmt/core.h> // Ex1 , fmt-library (sudo zypper install libfmt8 fmt-devel)
#include "includes/backward.hpp"  // Ex2, stack trace pretty printer for C++ (copy the headerfile from https://github.com/bombela/backward-cpp)
#include <nlohmann/json.hpp>  // Ex3, JSON library (sudo zypper install nlohmann_json-devel)
#include <cassert>  // for ex2
#include <fstream>  // for ex3

namespace bacward {
    backward::SignalHandling sh;
}

using json = nlohmann::json;

int main() {
    // EXERCISE 1
    fmt::print("Hello {}, today is {} {}.th of {} {}\n", "world", "thursday", 17, "august", 2023);
    fmt::print("int: {0:d}, hex: 0x{0:x}, bin: 0b{0:b}\n", 25);

    // EXERCISE 2
    //assert(0);
    
    /*
    a.out: main.cpp:15: int main(): Assertion `0' failed.
    Stack trace (most recent call last):
    #7    Object "[0xffffffffffffffff]", at 0xffffffffffffffff, in 
    #6    Object "./a.out", at 0x558a5fac3949, in 
    #5    Object "/lib64/libc.so.6", at 0x7f3916e7e24c, in __libc_start_main
    #4    Object "./a.out", at 0x558a5fac3cc6, in 
    #3    Object "/lib64/libc.so.6", at 0x7f3916e8bcf1, in __assert_fail
    #2    Object "/lib64/libc.so.6", at 0x7f3916e8bc69, in 
    #1    Object "/lib64/libc.so.6", at 0x7f3916e953e4, in abort
    #0    Object "/lib64/libc.so.6", at 0x7f3916e93d2b, in gsignal
    Aborted (Signal sent by tkill() 14046 1000)
    Aborted (core dumped)*/

    // EXERCISE 3
    std::ifstream input_file("animals.json");
    json data = json::parse(input_file);
    // Read data from a file
    std::cout << data << "\n";
    std::cout << data[1]["name"] << " is a " << data[1]["species"] << "\n";
    // Create a json object
    json ex3 = {
        {"happy", true},
        {"pi", 3.141},
    };
    // And write it to a file
    std::ofstream output_file("example.json");
    output_file << ex3;

    return 0;
}