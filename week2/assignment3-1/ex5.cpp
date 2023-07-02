#include <iostream>
#include <algorithm>
#include <vector>

/* Create a vector of pairs where each pair contains a string and 
 * an integer (like a name and an age). Sort the vector based on 
 * the integer.*/

bool sort_by_second_element(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    // a is previous pair in the vector and second is int/age
    return (a.second < b.second);
}

int main() {
    std::vector<std::pair <std::string, int>> vector_of_pairs{
        {"Mickey", 23}, {"Donald", 54}, {"Minnie", 23}, {"Daisy", 49}};
    // NTS When giving a function to stable_sort for a parameter (and not callig it), parenthesis can
    // be omitted. The function gets it's parameters from stable_sort
    std::stable_sort(vector_of_pairs.begin(), vector_of_pairs.end(), sort_by_second_element);

    for (const auto& pair : vector_of_pairs) {
        std::cout << pair.first << " " << pair.second << "\n";
    }

    return 0;
}