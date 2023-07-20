#ifndef EX_HPP
#define EX_HPP
#include <iostream>
#include <vector>

namespace Space {
    void hello() {
        std::cout << "Hello from the space!\n";
    }

    struct Space_location {  
        int x{3};
        int y{8};
        int z{2};

        // Overloading += operator for adding coordinates
        Space_location& operator+=(const Space_location& location) {
            x += location.x;
            y += location.y;
            z += location.z;
            return *this;
        }
        // Overloading -= operator for subtracting coordinates
        Space_location& operator-=(const Space_location& location) {
            x -= location.x;
            y -= location.y;
            z -= location.z;
            return *this;
        }
    };

    // Overloads are best to place in the namespace where they are used
    // Overloading << operator to print the location coordinates without cout
    std::ostream& operator<<(std::ostream& stream, const Space::Space_location& location) {
        stream << location.x << " " << location.y << " " << location.z << "\n";
        return stream;
    }

    // Overloading + operator to add two object types
    Space_location operator+(const Space_location& locat1, const Space_location& locat2) {
        Space_location final_location{locat1};
        final_location += locat2;
        return final_location;
    }

    // Overloading - operator to subtract two object types
    Space_location operator-(const Space_location& locat1, const Space_location& locat2) {
        Space_location final_location{locat1};
        final_location -= locat2;
        return final_location;
    }

} // namespace Space

struct Ship {
    static inline void hello() {
        std::cout << "Hello from the ship!\n";
    }
};

#endif