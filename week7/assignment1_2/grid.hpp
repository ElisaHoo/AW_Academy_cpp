#ifndef GRID_HPP
#define GRID_HPP
#include <vector>
#include <cassert>
#include <iostream>

// Template is used, because datatype of the objects that container contains can vary
template <typename T>  
class Grid_2D {
    public:
        // container's datatype is vector, to which the other container types refer
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
        // Obs it must be overloaded as a memeber function
        T& operator()(int row, int col);
        const T& operator()(int row, int col) const;

        Grid_2D<T>(int rows, int cols, T content) : grid(rows * cols, content), 
                    width{static_cast<long unsigned int>(rows)}, 
                    height{static_cast<long unsigned int>(cols)} {}
        

        void print_contents() {
            for (int x = 0; x < height; x++) {
                for (int y = 0; y < width; y++) {
                    //*this is class's instance itself
                    // we can't use grid(x, y), because it's std::vector
                    // and it doesn't have operator() overload
                    std::cout << (*this)(x, y);
                }
                std::cout << "\n";
            }
        }
                
        int size() {
            return grid.size(); 
        }

        iterator begin() {
            return grid.begin();
        }
        
        const_iterator cbegin() {
            return grid.begin();
        }

        iterator end() {
            return grid.end();
        }

        const_iterator cend() const {
            return grid.end();
        }
        
    private:
        storage_type grid;
};

template <typename T>
T& Grid_2D<T>::operator()(int row, int col) {
    assert(row >= 0 && row < width);
    assert(col >= 0 && row < height);

    return grid[row * width + col];
}

template <typename T>
const T& Grid_2D<T>::operator()(int row, int col) const {
    assert(row >= 0 && row < width);
    assert(col >= 0 && row < height);
     
    return grid[row * width + col];
}



#endif
