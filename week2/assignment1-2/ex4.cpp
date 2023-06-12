#include <iostream>
#include <list>
#include <algorithm>

/* Create a std::list<int> with 10 elements. Use std::adjacent_find
 * to find the first two adjacent elements that are equal. If no 
 * such elements exist, print a suitable message.*/

void find_two_adjacent_equals(std::list<int> l) {
    auto it = std::adjacent_find(l.begin(), l.end());
    if (it == l.end()){
        std::cout << "No matching adjacent elements\n";
    } else {
        std::cout << "The first adjacent equal element is "
                  << *it << "\n";
    }
}

int main() {
    std::list<int> l{1, 2, 3, 4, 4, 5, 6, 7, 8, 8};
    find_two_adjacent_equals(l);
    return 0;
}