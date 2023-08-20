#include "includes/grid_2d.hpp"

int main() {
    Grid_2D<int> g1(3, 3, 3);
    Grid_2D<int> g2 = g1;

    std::cout << g2(2, 2) << "\n";
    g2.print_contents();
    std::cout << "\n";

    
    Grid_2D<int> g3 = std::move(g1);
    g3.print_contents();
    std::cout << std::boolalpha << g1.empty() << "\n";
    std::cout << g3.max_size() << "\n";

    Grid_2D<int> g4(3, 3, 1);
    
    std::cout << (g2 == g3) << "\n";
    std::cout << (g2 != g3) << "\n";

    g2.swap(g4);
    g2.print_contents();

    return 0;
}