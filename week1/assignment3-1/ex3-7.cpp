#include <iostream>

/* Create a program with a struct that has a private 
 * member variable. Implement public functions for 
 * the private variable and demonstrate how the lifetime 
 * of the private variable is controlled by the struct.
 */

struct MyStruct {
    // private member variable
    private:
        int _number;

    public:
        // constructor
        MyStruct() {
            _number = 5;
        }

        // getter function to access private attributes from outside
        int get_number() {
            return _number;
        }

        // setter function to modify the private attribute
        void set_number(int new_number) {
            _number = new_number;
        }
};

int main() {
    MyStruct my_struct;
    // std::cout << my_struct._number;  ---> private variable is directly inaccessible!
    std::cout << "Default private attribute from MyStruct: " << my_struct.get_number() << "\n";
    my_struct.set_number(10);
    std::cout << "Modified private attribute from MyStruct: " << my_struct.get_number() << "\n";
    return 0;
}