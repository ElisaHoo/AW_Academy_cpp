#include <iostream>
#include <algorithm>
#include <vector>

/* Create a vector of strings and sort them in lexicographical order
 * = alphabetical order. Also, sort them based on the string length.*/

int main() {
    std::vector<std::string> words {"tiger", "donkey", "elephant", "cat", "dog"};
    std::sort(words.begin(), words.end());

    std::cout << "Lexicographical order: \n";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << "\n\n";

    std::sort(words.begin(), words.end(), [](const std::string& first, 
            const std::string& second) {return first.size() < second.size();});
    std::cout << "String length order: \n";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << "\n";

    return 0;
}