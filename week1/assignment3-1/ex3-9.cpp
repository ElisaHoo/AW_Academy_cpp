#include <iostream>

/* Create a program that uses static variables inside 
 * a function and demonstrates their lifetime across 
 * multiple function calls. Discuss with the students 
 * the lifetime and scope of static variables.
 */

void my_func() {
    // Static variables have program lifetime after they are created
    // so they retain their value between function calls (starting value)
    // does not change
    static int num{0};
    num += 1;
    std::cout << num << "\n";
}

int main() {
    for (int i = 0; i < 5; i++) {
        my_func();
    }
    
}