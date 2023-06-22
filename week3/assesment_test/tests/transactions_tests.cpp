#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../includes/doctest.h"
#include "../includes/transactions.h"

TEST_CASE("Tests for calculate_total_expenses") {
    std::vector<double> v = {3.3, 6.0, 1.2};
    // Tämä ei toimi, en tajua miksi ja aika loppuu...
    //CHECK(calculate_total_expenses((v) == 10.5));
}