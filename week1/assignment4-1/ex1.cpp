#include <iostream>
#include <algorithm>  // to use transform
#include <cassert>  // to use assert 

/* Write a C++ program that capitalizes the first letter 
 * of the string and sets the rest as lowercase letters. 
 * Use the following main function and write a function 
 * that passes the assertions.*/

std::string capitalize_string(std::string str);

int main() {
    assert(capitalize_string("the string challenge") == "The string challenge");
    std::cout << "Test 1 passed" << std::endl;
    assert(capitalize_string("THIS IS an ExamplE, should wORk!") == "This is an example, should work!");
    std::cout << "Test 2 passed" << std::endl;
    return 0;
}

std::string capitalize_string(std::string str) {
    // First lowercase the whole string
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    // And then uppercase the first letter
    str[0] = std::toupper(str[0]);
    return str;
}