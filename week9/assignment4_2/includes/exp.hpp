#ifndef EXP_HPP
#define EXP_HPP
#include <iostream>
#include <string>
#include "expected.hpp" // if std-lib is too old for <expected>

enum class error {
    error_creating_instance,
};

class Exp {
    public:
        // Obs! tl::expected instead of std::expected
        static tl::expected<Exp, error> create_instance(bool succeed) {
            if (succeed) {
                return Exp();
            }
            // And same with tl::unexpected vs std::unexpected
            return tl::unexpected{error::error_creating_instance};
        }
        
    private: 
};

#endif