#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP
#include <cstdint>
#include <vector>
#include <iostream>

// This was left unfinished, doesn't work

template <typename T, std::size_t Mem_byte_size>
class Custom_static_allocator {
    public:
        using value_type = T;

        Custom_static_allocator() = default;

        [[nodiscard]] T* allocate(std::size_t n) {
            return new (mem_block) T;
        }
        void deallocate(T* p, std::size_t) {
            p->~T();  // Calling destructor
        }

    private:
        static uint8_t mem_block[Mem_byte_size];
};

#endif