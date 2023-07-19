#include <iostream>
#include <vector>
#include <algorithm>

/* Create a function that will remove all instances of a value 
 * from the vector and inform if the value was found and removed.*/

void remove_elements(std::vector<int> v, int value) {
    // numbers are removed only logically...
    std::vector<int>::iterator modified = std::remove(v.begin(), v.end(), value);
    int size_before = v.size(); // ...and size remains unchanged
    // Numbers are erased physically...
    v.erase(modified, v.end());
    int size_after = v.size();  // ... and now size is changed
    if (size_before > size_after) {
        std::cout << "Value(s) found and removed!\n";
    } else {
        std::cout << "The searched value was not found\n";
    }
}

int main() {
    std::vector<int> v{2, 7, 9, 2, 0, 1, 4, 2};
    remove_elements(v, 2);
    return 0;
}