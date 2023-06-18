#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

/* Create a vector<int> with 10 numbers in it. 
 * Use std::partition to separate the even and 
 * odd numbers. Print out the vector after partitioning.*/

void separate_evens_and_odds(std::vector<int> v) {
    auto it = std::partition(v.begin(), v.end(), [](int i) {return i % 2 == 0;});
    std::cout << "Partitioned vector: ";
    std::copy(std::begin(v), it, std::ostream_iterator<int>(std::cout, " "));
    std::cout << "* ";
    std::copy(it, std::end(v), std::ostream_iterator<int>(std::cout, " "));
}

int main() {
    std::vector<int> v{2, 5, 9, 12, 43, 61, 80, 6, 1, 78};
    separate_evens_and_odds(v);
    return 0;
}