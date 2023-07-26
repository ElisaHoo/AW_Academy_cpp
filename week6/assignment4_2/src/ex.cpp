#include "../includes/ex.hpp"

Supernatural::Creature::Creature(const char& human_type) {
    human_id = human_type;
    type = Type::human;
}

Supernatural::Creature::Creature(const int& robot_type) {
    robot_id = robot_type;
    type = Type::robot;
}

Supernatural::Creature::Creature(const float& alien_type) {
    alien_id = alien_type;
    type = Type::alien;
}

std::string Supernatural::Creature::check_type() const{
    switch (type)
    {
    case Type::human:
        {
            return "human\n";
        }
    case Type::robot:
        {
            return "robot\n";
        }
    case Type::alien:
        {
            return "alien\n";
        }
    }
    return "The type is not defined\n";
}

char Supernatural::Creature::return_human_identifier() const{
    if (type != Type::human) {
        throw std::runtime_error(
            "You tried to use 'return_human_identifier()' "
            "-function to non-human-type object"
        );
    }
    return human_id;
}

int Supernatural::Creature::return_robot_identifier() const{
    if (type != Type::robot) {
        throw std::runtime_error(
            "You tried to use 'return_robot_identifier()' "
            "-function to non-robot-type object"
        );
    }
    return robot_id;
}

float Supernatural::Creature::return_alien_identifier() const{
    if (type != Type::alien) {
        throw std::runtime_error(
            "You tried to use 'return_alien_identifier()' "
            "-function to non-alien-type object"
        );
    }
    return alien_id;
}

Supernatural::Creature Supernatural::Creature::create_creature(const std::string& input) {
    if (is_int(input)) {
        int integer{std::stoi(input)};
        return Creature(integer);
    
    } else if (is_float(input)) {
        return Creature(std::stof(input));
    
    } else {
        for (auto letter : input) {
            // Writing the full name is ok (and it can also contain a dash) 
            // -> otherwise exception
            if (!isalpha(letter) && (letter != '-')) {
                throw std::invalid_argument(
                    "The string input should represent an integer (robot), "
                    "a float (alien) or a char (human)");
            }
        }
        return input[0]; // Returns the first letter of the name
    }
}

bool Supernatural::is_float(std::string_view input) {
    double val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

bool Supernatural::is_int(std::string_view input) {
    int val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

void Supernatural::Create_from_file::create_vector_of_objects(std::string& filename) {
    // Read file and get the file contents to a vector
    std::vector<std::string> vector_of_lines{Create_from_file::read_file(filename)};
    for (int i = 0; i < vector_of_lines.size(); ++i) {
        // Create objects by using file contents and push objects to a vector
        vector_of_creature_obj.push_back(Creature::create_creature(vector_of_lines[i]));
    }
}

std::vector<std::string> Supernatural::Create_from_file::read_file(std::string& filename) {
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        throw std::runtime_error("Error opening the file, please check that the file exists");
    }
    std::vector<std::string> vector_of_lines;
    std::string line;

    while (!input_file.eof()) {
        std::getline(input_file, line);
        vector_of_lines.push_back(line);
    }
    input_file.close();
    return vector_of_lines;
}