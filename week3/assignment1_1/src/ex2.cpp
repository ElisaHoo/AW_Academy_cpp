#include "../includes/ex.h"


int find_maximum_value(std::vector<int> numbers) {
    // Check if vector's size is zero = empty and return error code
    if (numbers.size() == 0) {
        return ERROR_CODE;
    }
    std::vector<int>::iterator result;
    result = std::max_element(numbers.begin(), numbers.end());
    return *result;
}