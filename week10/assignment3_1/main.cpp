#include "includes/allocator.hpp"

int main() {
    std::vector<int, Custom_static_allocator<int, 1024>> vec;

    return 0;
}