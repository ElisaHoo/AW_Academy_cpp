#ifndef EX1_HPP
#define EX1_HPP
#include <iostream>
#include <cassert>
#include <charconv>
#include <string_view>
#include <string>
#include <vector>
#include <fstream>

namespace Supernatural {

    bool is_float(std::string_view input);

    bool is_int(std::string_view input);

    // Stores type of an object
    enum class Type {
        robot,
        human,
        alien
    };
    
    class Creature {
        public:
            // Default constructor makes human-type if user don't give any arguments
            Creature() = default;
            // Own constructors for different types
            Creature(const char& human_type);
            Creature(const int& robot_type);
            Creature(const float& alien_type);
            // To check what type is stored to object
            std::string check_type() const;
            // To get the value/id of the stored type
            char return_human_identifier() const;
            int return_robot_identifier() const;
            float return_alien_identifier() const;
            // Creates a new creature by the string-input given by the user
            static Creature create_creature(const std::string& input);

        private:
            // Stores creature's id
            union {
                char human_id;  // first letter of the name
                int robot_id;  // id-number
                float alien_id;  // approx wavelength of the light alien's eyes emit
            };
            Type type;
    };

    // Overload the << operator for the class to directly output it's 
    // contents with std::cout
    inline std::ostream& operator<<(std::ostream& stream, const Supernatural::Creature& creature) {
        stream << creature.check_type();
        return stream;
    }

    class Create_from_file : public Creature {
    public:
        Create_from_file() = default;
        Create_from_file(std::string filename) {
            // Creates vector of creature objects when user calls constructor with filename 
            //as argument
            create_vector_of_objects(filename);
        }
        void create_vector_of_objects(std::string& filename);
        std::vector<Creature> vector_of_creature_obj;
        
    private:
        std::string line_content;
        // Read file and get it's contents into vector
        static std::vector<std::string> read_file(std::string& filename);
    };

    inline std::ostream& operator<<(std::ostream& stream, const Create_from_file& content) {
        for (auto& obj : content.vector_of_creature_obj) {
            stream << obj.check_type();
        }
        return stream;
    }

} // namespace Supernatural

#endif


