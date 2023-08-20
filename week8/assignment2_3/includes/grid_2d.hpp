#ifndef GRID_2d_HPP
#define GRID_2d_HPP
#include <vector>
#include <cassert>
#include <iostream>

// Template is used, because datatype of the objects that container contains can vary
template <typename T>  
class Grid_2D {
    public:
        // container's datatype is std::vector, to which the other container types refer
        using storage_type = std::vector<T>;  
        using value_type = typename storage_type::value_type;
        using reference = typename storage_type::reference;
        using const_reference = typename storage_type::const_reference;
        using iterator = typename storage_type::iterator;
        using const_iterator = typename storage_type::const_iterator;
        using difference_type = typename storage_type::difference_type;
        using size_type = typename storage_type::size_type;
        size_type width;
        size_type height;

        // Accessing to grid element by overloading operator()
        T& operator()(int row, int col);
        const T& operator()(int row, int col) const;

        Grid_2D<T>() = default;

        Grid_2D<T>(int rows, int cols, T content) : grid(rows * cols, content), 
                    width{static_cast<long unsigned int>(rows)}, 
                    height{static_cast<long unsigned int>(cols)} {}
        
        ~Grid_2D<T>() = default;
        
        // Copy constructor
        Grid_2D<T>(Grid_2D<T>& other) = default;

        // Move constructor
        Grid_2D<T>(Grid_2D<T>&& other) = default;       
 
        // User-defined copy assignment operator (copy-and-swap idiom)
        Grid_2D<T>& operator=(const Grid_2D<T>& other) = default;

        // User-defined move assignment operator
        Grid_2D<T>& operator=(Grid_2D<T>&& other) = default;

        void print_contents() {
            for (int x = 0; x < height; x++) {
                for (int y = 0; y < width; y++) {
                    //'*this' is class's instance itself
                    // we can't use grid(x, y), because container's storage type is std::vector
                    // and it doesn't have operator() overload
                    std::cout << (*this)(x, y);
                }
                std::cout << "\n";
            }
        }

        int size() {
            return grid.size(); 
        }

        bool empty() {
            return grid.begin() == grid.end();
        }

        long long max_size() {
            return grid.max_size();
        }

        void swap(Grid_2D<T>& other) {
            std::swap(grid, other.grid);
        }

        iterator begin() {
            return grid.begin();
        }

        const iterator begin() const{
            return grid.begin();
        }

        const_iterator cbegin() {
            return grid.begin();
        }

        iterator end() {
            return grid.end();
        }

        const iterator end() const{
            return grid.end();
        }

        const_iterator cend() const {
            return grid.end();
        }

    private:
        storage_type grid;
};

template <typename T>
bool operator==(Grid_2D<T>& lhs, Grid_2D<T>& rhs) {
    return (std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
} 

template <typename T>
bool operator!=(const Grid_2D<T>& lhs, const Grid_2D<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T>
T& Grid_2D<T>::operator()(int row, int col) {
    assert(row >= 0 && row < width);
    assert(col >= 0 && row < height);

    return grid[row * height + col];
}

template <typename T>
const T& Grid_2D<T>::operator()(int row, int col) const {
    assert(row >= 0 && row < width);
    assert(col >= 0 && row < height);

    return grid[row * height + col];
}

#endif