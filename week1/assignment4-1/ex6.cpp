#include <iostream>
#include <cassert>

/* Write a C++ program that simulates a simple game. 
 * Implement a function called play_game() that takes 
 * a number as input and checks if it is within a certain 
 * range. Use assert statements to check if the number is 
 * within the range of 1 to 100 (inclusive). If the assertion 
 * fails, display an error message indicating that the number 
 * is out of range. Compile the program both with and without 
 * the NDEBUG macro defined and observe the behaviour when the 
 * assertion fails in each case.*/

bool play_game(int number) {
    return (number > 0 && number <= 100);
}

int main() {
    std::cout << "Please enter a number for playing a game! ";
    int number{};
    std::cin >> number;

    assert((play_game(number)) && "G A M E   O V E R! The number is out of the range");

    std::cout << "Well done, the number is in the range!\n";

    return 0;
}
