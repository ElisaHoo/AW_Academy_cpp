#include <iostream>

/* Write a program that dynamically allocates memory for 
 * an array inside a function. Pass the array to another 
 * function and print its values. Remember to deallocate 
 * the memory at the end. Discuss with the students the 
 * concept of dynamic memory allocation and how it affects 
 * the lifetime of variables.
 */

void print_array(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int* create_array(int size) {
    int* array = new int[size];

    for (int i =0; i < size; ++i) {
        array[i] = i;
    }
    return array;
}

int main() {
    int size = 10;
    int* my_array = create_array(size);

    print_array(my_array, size);

    delete[] my_array;  // Remember deallocate the memory! Use [] after delete if array!

    return 0;
}

