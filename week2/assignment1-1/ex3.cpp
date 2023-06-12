#include <iostream>
#include <vector>
#include <numeric>

/* Create a program that has a function that receives the sum 
 * of all the elements in an array. The vector will be filled 
 * automatically with different numbers*/

void sum_of_elements(std::vector<int> vect) {
    int sum{std::accumulate(vect.begin(), vect.end(), 0)};
    std::cout << "The sum is " << sum << "\n";
}

int main() {
    std::vector<int> random_number_vector;
    for (int i = 0; i < 10; i++) {
        // Generate random numbers between 1-100
        random_number_vector.push_back(rand() % 100 + 1);
        std::cout << random_number_vector[i] << " ";
    }
    std::cout << "\n";
    sum_of_elements(random_number_vector);
    
    return 0;
}