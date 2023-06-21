/* Pascal's triangle
 * Create unit tests to make sure that your program works 
 * as intended*/

#include "includes/pascal.h"
 
int main(){
    std::cout << "** Pascal's Triangle **\n";
    std::cout << "Please enter a number of rows:";
    int rows{};
    std::cin >> rows;
    std::cout << "\n";

    // Print each row
    for(int n = 1; n <= rows; ++n){
 
        // Print spaces on triangle's sites
        for(int j = 1; j < rows - n + 1; ++j) {
            std::cout << "  ";
        }
 
        // Print values
        int value{1};
        for(int i = 1; i <= n; ++i){
            std::cout << value <<"   ";
            value = triangle_value(rows, value, n, i);
        }
        std::cout << "\n";
    }
    return 1;
}