#ifndef HEAP_ARRAY_HPP
#define HEAP_ARRAY_HPP
#include <iostream>
#include <cassert>

template <typename T, int arr_size>
class Heap_array {
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;
        using size_type = int;

        // Default constructor
        Heap_array() = default;
        // List initializer constructor
        Heap_array(std::initializer_list<T> list_elements) {
            assert((arr_size == list_elements.size()) 
                    && "The number of elements does not match the size of the array");
            // Gives pointer to memory block, which contains the array
            heap_arr = new T[arr_size] {};
            int i = 0;
            for (auto& element: list_elements) {
                heap_arr[i] = element;
                i++;
            }
        }

        // Copy constructor
        Heap_array(const Heap_array& other) {
            heap_arr = new T[arr_size] {};
            for (int i = 0; i < arr_size; i++) {
                heap_arr[i] = other.heap_arr[i];
            }
        }

        // Move constructor
        Heap_array(Heap_array&& other) {
            heap_arr = other.heap_arr;
            other.heap_arr = nullptr;
        }

        // Destructor
        ~Heap_array() {
            delete[] heap_arr;
        }

        iterator begin() {
            // Returns the memory address of heap_arr[0]
            return &heap_arr[0];
        }
        
        iterator end() {
            return &heap_arr[arr_size];
        }

        const iterator begin() const {
            return &heap_arr[0];
        }
        
        const iterator end() const {
            return &heap_arr[arr_size];
        }

        const_iterator cbegin() {
            return &heap_arr[0];
        }

        const_iterator cend() {
            return &heap_arr[arr_size];
        }

        int size() {
            return std::distance(&heap_arr[0], &heap_arr[arr_size]);
        }

        void swap(Heap_array& other) {
            std::swap(heap_arr, other.heap_arr);
        }

        bool empty() {
            return &heap_arr[0] == &heap_arr[arr_size];
        }

        T& operator[](int index) {
            return heap_arr[index];
        }

    private:
        T* heap_arr = nullptr;
};

#endif