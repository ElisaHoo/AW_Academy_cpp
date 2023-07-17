#ifndef EX1_HPP
#define EX1_HPP
#include <iostream>
#include <random>

enum class Status {
    success,
    runtime_error,
    syntax_error,
    mystical_error,
};

Status return_random_status();

#endif