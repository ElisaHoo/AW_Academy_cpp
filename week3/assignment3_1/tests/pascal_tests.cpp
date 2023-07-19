#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../includes/doctest.h"
#include "../includes/pascal.h"

TEST_CASE("Tests for pascals triangle") {
    CHECK((triangle_value(5, 3, 4, 3) == 1));
}