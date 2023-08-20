#include "includes/heap_array.hpp"

int main() {
    // Create array with five elements, print the elements and array's size
    Heap_array<int, 5> a1 = {6, 78, 0, 1, 59};
    for (int i = 0; i < a1.size(); i++) {
        if (i == (a1.size() -1)) {
            std::cout << a1[i] << "\n";
            break;
        }
        std::cout << a1[i] << ", ";
    }
    std::cout << "Size of the array a1 is " << a1.size() << "\n";

    // Create empty array
    Heap_array<int, 0> a;
    std::cout << std::boolalpha << "Array 'a' is empty: " << a.empty() << "\n";
    std::cout << std::boolalpha << "Array 'a1' is empty: " << a1.empty() << "\n";

    // Re-assign one element and print it
    a1[3] = 8;
    std::cout << a1[3] << "\n";

    // Copy array
    Heap_array<int, 5> a2 = a1;
    std::cout << "After copy, original array's a1 contents:\n";
    for (int i = 0; i < a1.size(); i++) {
            if (i == (a1.size() -1)) {
                std::cout << a1[i] << "\n";
                break;
            }
            std::cout << a1[i] << ", ";
    }
    std::cout << "After copy, copied array's a2 contents:\n";
    for (int i = 0; i < a2.size(); i++) {
        if (i == (a2.size() -1)) {
            std::cout << a2[i] << "\n";
            break;
        }
        std::cout << a2[i] << ", ";
    }

    // Move array (array "in memory block a1" disappears)
    Heap_array<int, 5> a3 = std::move(a1);
    std::cout << "After move, moved array's a3 contents:\n";
    for (int i = 0; i < a3.size(); i++) {
        if (i == (a3.size() -1)) {
            std::cout << a3[i] << "\n";
            break;
        }
        std::cout << a3[i] << ", ";
    }

    std::cout << std::boolalpha << "Array 'a1' is empty: " << a1.empty() << "\n";

    // Swap two arrays
    Heap_array<int, 5> a4 = {1, 2, 3, 4, 5};
    a3.swap(a4);

    std::cout << "a3-array's contents:\n";
    for (int i = 0; i < a3.size(); i++) {
        if (i == (a3.size() -1)) {
            std::cout << a3[i] << "\n";
            break;
        }
        std::cout << a3[i] << ", ";
    }
    std::cout << "a4-array's contents:\n";
    for (int i = 0; i < a4.size(); i++) {
        if (i == (a4.size() -1)) {
            std::cout << a4[i] << "\n";
            break;
        }
        std::cout << a4[i] << ", ";
    }

    std::cout << std::boolalpha << "a3 == a4: " << (a3 == a4) << "\n";
    std::cout << std::boolalpha << "a3 != a4: " << (a3 != a4) << "\n";

    std::cout << "a3 max size: " << a3.max_size() << "\n";
    
    return 0;
}