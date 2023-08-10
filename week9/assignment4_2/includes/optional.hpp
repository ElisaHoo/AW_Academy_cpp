#ifndef OPTIONAL_HPP
#define OPTIONAL_HPP
#include <iostream>
#include <optional>
#include <string>

class Opt {
    public:
        static std::optional<Opt> create_instance(bool succeed) {
            if (succeed) {
                return Opt();
            }
            return std::nullopt;
        }
        
    private: 
};

#endif