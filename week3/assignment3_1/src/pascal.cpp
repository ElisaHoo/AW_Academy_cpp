#include "../includes/pascal.h"

// Function to count values to triangle
int triangle_value(int row_num, int val, int n, int i){   
    val = val * (n - i)/i;
    return val;
}