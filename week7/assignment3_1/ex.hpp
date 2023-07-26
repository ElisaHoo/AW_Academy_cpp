#ifndef EX_HPP
#define EX_HPP
#include <iostream>

template <typename Derived>
struct Type_printing {
    void print_type() const {
        std::cout << typeid(Derived).name() << "\n";
    }
};

template <typename D>
class Compare {
};

// "Crpt"-class derives from a template type "Compare" and "Type_printing",
// with the Crpt -class itself as an argument
class Crtp : public Compare<Crtp>, public Type_printing<Crtp> {
    public:
        Crtp() = default;
        Crtp(int new_value) : internal_value(new_value) {}
        bool operator==(const Crtp& other_value) const {
            return internal_value == other_value.internal_value;
        }
        bool operator>(const Crtp& other_value) const {
            return internal_value > other_value.internal_value;
        }
    private:
        int internal_value;
};

// Compare-class's operator overloads
template <typename D>
bool operator==(const Compare<D>& lhs, const Compare<D>& rhs) {
    return (!(static_cast<D>(lhs) > static_cast<D>(rhs)) &&
           !(static_cast<D>(lhs) < static_cast<D>(rhs)));
}

template <typename D>
bool operator>(const Compare<D>& lhs, const Compare<D>& rhs) {
    return (static_cast<D>(lhs) > static_cast<D>(rhs));
}

#endif