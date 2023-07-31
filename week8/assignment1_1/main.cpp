/* Exercise 1
 * Create a stack variable of any fundamental type in main() function 
 * (so just an usual declaration).  Then print out its memory address.
 * Create a function in the same program and do the same.  
 * Compute the difference between the addresses and print that out too.
 * 
 * Exercise 2
 * std::vector uses heap memory internally to store its contents.  
 * Create an std::vector, throw in some elements and print out the address 
 * of the vector itself and all of its elements.  Think about what you see.  
 * Is the vector's position in the memory same as its contents?  Why?
 * 
 * Exercise 3
 * Elements being contiguous in memory is an important concept.  
 * This means they are located in the memory one after another.
 * Create a (template) function that takes a container as its input, 
 * and checks if the elements in the container are next to each other.
 * Create few container types (list, vector, array, deque) and check if 
 * this holds true.  Try it with different counts of elements (e.g. with 1000, 
 * 1000000, 100000000 elements)
 * 
 * Exercise 4
 * Check if std::vector of std::vectors is contiguous.*/

#include <iostream>
#include <vector>
#include <array>
#include <deque>

template <typename T>
bool check_contiquous_v_of_v(T cont){
    for (int i = 0; i < cont.size(); i++) {
        for (int j = 0; j < cont[i].size(); j++)
            if (&cont[i][j+1] - &cont[i][j] != 1) {
                return false;
            }
    }
    return true;
}



template <typename T>
bool check_contiquous(T cont){
    for (int i = 0; i < cont.size(); i++) {
        // Subtraction of pointers (to memory addresses) is one, 
        // if addresses are located next to each other
        if ((&cont[i+1] - &cont[i]) != 1) {
            return false;
        }
    }
    return true;
}

// Jari's (teacher's) solution to ex3
/* template <typename T>
bool is_contiquous(const T& container) {
    auto it_first = std::begin(container);
    auto it_second = std::next(it_first);
    auto it_end = std::end(container);

    while (it_second != it_end) {
        if (&(*it_second) - &(*it_first) != 1) {
            return false;
        }
        ++it_first;
        ++it_second;
    }
    return true;
}    */

int return_num() {
    return 3;
}

int main() {
    // EXERCISE 1 -> variables and functions are located different place in memory
    int num{3};
    std::cout << "Integer's memory adress is: " << &num << "\n"; 
    auto func_ptr{&return_num};
    std::cout << "Function's memory adress is: " << reinterpret_cast<int*>(func_ptr) << "\n";

    // EXERCISE 2 -> Vector is in the stack-memory and elements are in heap
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::cout << "The address of vector itself is: " << &vec << "\n";
    std::cout << "And it's elements addresses are:\n";
    for (auto& element: vec) {
        std::cout << &element << "\n";
    }

    // EXERCISE 3
    std::vector<int> vec2(100000);
    std::cout << "Elements in the vector are next to each other: " 
              << std::boolalpha << check_contiquous(vec2) << "\n";  //TRUE
    std::array<int, 10000> arr;
    std::cout << "Elements in the array are next to each other: " 
            << std::boolalpha << check_contiquous(arr) << "\n";  // TRUE
    std::deque<int> lista(1000000);
    std::cout << "Elements in the deque are next to each other: " 
            << std::boolalpha << check_contiquous(lista) << "\n";  // FALSE

    // EXERCISE 4
    std::vector<std::vector<int>> vec_of_vec(10, std::vector<int>(1000000,1));
    std::cout << "Elements in the vector of vectors are next to each other: " 
            << std::boolalpha << check_contiquous_v_of_v(vec_of_vec) << "\n";  //TRUE

    return 0;
} 