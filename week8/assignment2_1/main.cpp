/* Exercise 1
 * Create a function that takes universal reference as is argument (template T&&) 
 * to print out whether or not its argument is an lvalue reference or an rvalue 
 * reference
 * Make a program and call the function to demonstrate both cases.
 * 
 * Exercise 2
 * Create a class with following properties:
 * Has template parameter that enables or disables console output
 * Counts number of calls to
 * Default constructor
 * Copy constructor
 * Move constructor
 * Destructor
 * If enabed, prints out when its constructor / destructor is called
 * This kind of class will be your friend while debugging.
 * 
 * Exercise 3
 * Earlier, we created a class that counted the number of instances 
 * created.  Delete the classes copy constructor and implement 
 * the move constructor.
 * (This kind of class is extremely useful when wrapping libraries.  
 * You can avoid user having to deal with library initialisation / destruction 
 * by doing the init on the first created instance of a type and then cleaning 
 * up when the last goes poof.  If you have tried libraries such as SDL, GLFW, 
 * or other low-level windowing libraries, this is the way to go.)*/

#include <iostream>
#include <type_traits>

// A forwarding (or global) reference is an rvalue reference to a cv-unqualified (=fundamental & compound types) template parameter
template <typename T>
void check_argument_value(T&&) {
    if constexpr(std::is_rvalue_reference_v<T&&>) {
        std::cout << "Argument is rvalue reference\n";
    } else if constexpr(std::is_lvalue_reference_v<T&&>) {
        std::cout << "Argument is lvalue reference\n";
    } else {
        std::cout << "Argument is not rvalue or lvalue reference\n";
    }
}

template <bool print>
class Counter {

    public:
        static inline int def_count{0};
        static inline int copy_count{0};
        static inline int move_count{0};

        Counter() {
            def_count++;
            if constexpr(print) {
                std::cout << "Default constructor is called\n";
            }
        }

        Counter(const Counter& other) {
            copy_count++;
            if constexpr(print) {
                std::cout << "Copy constructor is called\n";
            }
        }

        Counter(Counter&& other) {
            move_count++;
            if constexpr(print) {
                std::cout << "Move constructor is called\n";
            }
        }

        ~Counter() {
            if constexpr(print)
            {
                std::cout << "Destructor is called (ex2)\n";
            }
        }

    private:
};

class Instance {

    public:
        Instance() {
            instances++;
        }
        Instance(const Instance& instance) = delete;
        
        // Moves are not counted up
        Instance(Instance&& other) {
            moved = true;
        } 

        // Moves are not counted down
        ~Instance() {
            if (!moved) {
                instances--;
            }
        }
        void print_instance_count() {
            std::cout << "There are " << instances << " instances (ex 3)\n";
        }
    private:
        static inline int instances{0};
        bool moved{false};
};

int main() {
    // EXERCISE 1
    int num = 3;
    int& num_lr = num;  // lvalue reference
    std::string s{"Hello"};
    check_argument_value(num_lr);
    check_argument_value(std::move(s));  //rvalue reference
    
    // EXERCISE 2
    Counter<true> c1;
    Counter<true> c2(c1);
    Counter<true> c3(std::move(c1));
    Counter<false> c4;  // The console output is disabled
    Counter<false> c5(std::move(c4));  // The console output is disabled
    std::cout << "\nStats are: \n";
    std::cout << "Default constructor calls: " << Counter<true>::def_count + Counter<false>::def_count << "\n";
    std::cout << "Copy constructor calls: " << Counter<true>::copy_count << "\n";
    std::cout << "Move constructor calls: " << Counter<true>::move_count + Counter<false>::move_count << "\n\n";

    // EXERCISE 3
    Instance inst1;
    Instance inst2(std::move(inst1));
    Instance inst3;
    Instance inst4;
    Instance inst5(std::move(inst4));
    inst5.print_instance_count();  // 3 instances
    return 0;
}