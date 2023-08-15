#include "includes/planet.h"
#include "includes/position_comparison.h"

#include <iostream>
#include <numeric>
#include <vector>
#include <thread>
#include <future>
#include <functional>

int main()
{
    Planet planet1{0, 5, 2};
    Planet planet2{-10, 7, -94};
    Planet planet3{6042, 4, 8};
    Planet planet4{-42, 55, 92};
    Planet planet5{0, -54189072, 0};

    std::vector<Planet> planets = {planet1, planet2, planet3, planet4, planet5};

    // A thread for each axis to count the time steps passed before the planets are in their starting position
    std::future<int> future_x = std::async(std::launch::async, calculate_orbital_period_x, std::ref(planets));

    std::future<int> future_y = std::async(std::launch::async, calculate_orbital_period_y, std::ref(planets));

    std::future<int> future_z = std::async(std::launch::async, calculate_orbital_period_z, std::ref(planets));

    // We get the orbital periods for axis x, y and z until all threads are in their starting positions
    int period_x{future_x.get()};
    int period_y{future_y.get()};
    int period_z{future_z.get()};

    // Calculate least common factor for an orbital period
    int lcm_xy{std::lcm(period_x, period_y)};
    int result{std::lcm(lcm_xy, period_z)};

    std::cout << "Time period all planets are back to their starting positions: " << result << '\n';

    return 0;
}