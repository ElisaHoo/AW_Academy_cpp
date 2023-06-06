#include <iostream>
#include <string>
#include <cctype>

// A program that will verify if the password is strong

std::string get_password();
bool is_long_enough(std::string password);
bool has_uppercase_letter(std::string password);
bool has_lowercase_letter(std::string password);
bool has_digit(std::string password);
bool has_special_character(std::string password);
void is_password_strong(bool long_enough, bool uppercase, bool lowercase, bool digit, bool special_character);


int main() {
    std::string password{get_password()};
    bool long_enough{is_long_enough(password)};
    bool uppercase{has_uppercase_letter(password)};
    bool lowercase{has_lowercase_letter(password)};
    bool digit{has_digit(password)};
    bool special_character{has_special_character(password)};
    is_password_strong(long_enough, uppercase, lowercase, digit, special_character);

    return 0;
}


// Get input/password from a user
std::string get_password() {
    std::cout << "Please enter a password: ";
    std::string password{};
    std::cin >> password;
    return password;
}


// At least 8 characters long
bool is_long_enough(std::string password) {
    if (password.length() >= 8)
        return true;
    return false;
}


// Contains at least one uppercase letter
bool has_uppercase_letter(std::string password) {
    for (char ch: password) {
        if (std::isupper(ch)) {
            return true;
        } 
    }
    return false;
}


// Contains at least one lowercase letter
bool has_lowercase_letter(std::string password) {
    for (char ch: password) {
        if (std::islower(ch)) {
            return true;
        }
    }
    return false;
}


// Contains at least one digit
bool has_digit(std::string password) {
    for (char ch: password) {
        if (std::isdigit(ch)) {
            return true;
        }
    }
    return false;
}


// Contains at least one special character (e.g., @, #, $)
bool has_special_character(std::string password) {
    for (char ch: password) {
        // Check if character's ASCII value corresponds special characters value
        if ((ch <= 47) || (ch >= 58 && ch <=64) ||
           (ch >= 91 && ch <= 96) || (ch >= 123))
           {
            return true;
           }
    }
    return false;
}


// Check if pw is strong
void is_password_strong(bool long_enough, bool uppercase, bool lowercase, bool digit, bool special_character) {
    if (long_enough && uppercase && lowercase && digit && special_character) {
        std::cout << "Your password is strong!" << "\n";
    } else {
        std::cout << "Your password is weak!" << "\n";
    };
}