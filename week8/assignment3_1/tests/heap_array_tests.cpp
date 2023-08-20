#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../includes/doctest.h"
#include "../includes/heap_array.hpp"

TEST_CASE("Testing Heap_array -class") {
        Heap_array<int, 0> def;  // Default constr.
        Heap_array<int, 5> list = {1, 2, 3, 4, 5};  // List_init constr.
        Heap_array<int, 5> to_be_moved = {6, 7, 8, 9, 10};
        Heap_array<int, 5> copy(list);  // Copy constr.
        Heap_array<int, 5> move(std::move(to_be_moved));  // Move constr.
    
    SUBCASE("Constructors make the objects with correct size + "
            "size() and empty() are working") {
        CHECK(def.size() == 0);
        CHECK(def.empty());
        CHECK(list.size() == 5);
        CHECK(!list.empty());
        CHECK(copy.size() == 5);
        CHECK(!copy.empty());
        CHECK(move.size() == 5);
        CHECK(!move.empty());
    }

    SUBCASE("Constructors make the objects with the right content + "
            "accessing element (operator[]) works") {
        CHECK(list[0] == 1);
        CHECK(list[1] == 2);
        CHECK(list[2] == 3);
        CHECK(list[3] == 4);
        CHECK(list[4] == 5);
        CHECK(copy[0] == 1);
        CHECK(copy[1] == 2);
        CHECK(copy[2] == 3);
        CHECK(copy[3] == 4);
        CHECK(copy[4] == 5);
        CHECK(move[0] == 6);
        CHECK(move[1] == 7);
        CHECK(move[2] == 8);
        CHECK(move[3] == 9);
        CHECK(move[4] == 10);
    }

    SUBCASE("Iterators are working") {
        CHECK(std::distance(list.begin(), list.end()) == 5);
    }

    SUBCASE("Swap() is working") {
        copy.swap(move);
        CHECK(copy[0] == 6);
        CHECK(copy[1] == 7);
        CHECK(copy[2] == 8);
        CHECK(copy[3] == 9);
        CHECK(copy[4] == 10);
        CHECK(move[0] == 1);
        CHECK(move[1] == 2);
        CHECK(move[2] == 3);
        CHECK(move[3] == 4);
        CHECK(move[4] == 5);
    }

    SUBCASE("== and != operators are working") {
        CHECK(!(list == move));
        CHECK(list != move);
    }

    SUBCASE("max_size() works") {
        CHECK(list.max_size() == INT_MAX);
    }
}