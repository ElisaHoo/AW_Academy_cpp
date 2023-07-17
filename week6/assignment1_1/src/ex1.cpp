#include "../includes/ex1.hpp"

Status return_random_status() {
    std::random_device rd;  // A seed source for the random number engine
    std::mt19937 gen(rd());  // Mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, 2);
    // Use distrib to transform the random unsigned int
    // generated by gen into an int in 0-2
    int num{distrib(gen)};
    if (num == 0) {
        return Status::success;
    } else if (num == 1) {
        return Status::runtime_error;
    } else if (num == 2) {
        return Status::syntax_error;
    }
    return Status::mystical_error;
}