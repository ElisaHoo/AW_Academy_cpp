#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../includes/doctest.h"
#include "../includes/iterator.hpp"

TEST_CASE("Tests for iterator") {
    std::string abc{"abcäö♫⭐"};
    Codepoint_it it{abc.begin()};

    CHECK(static_cast<int>(*it) == 97); // Letter 'a' ASCII code is 97 in decimals
    ++it;
    CHECK(static_cast<int>(*it) == 98);
    ++it;
    CHECK(static_cast<int>(*it) == 99);
    ++it;
    CHECK(static_cast<int>(*it) == 228);
    ++it;
    CHECK(static_cast<int>(*it) == 246);
    ++it;
    CHECK(static_cast<int>(*it) == 9835);
    ++it;
    CHECK(static_cast<int>(*it) == 11088);
}