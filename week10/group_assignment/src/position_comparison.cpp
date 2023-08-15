#include "../includes/position_comparison.h"

// Function to compare x axis and change the velocity
void compare_position_x(Planet &planet1, Planet &planet2)
{
    if (planet1.current_position.x > planet2.current_position.x)
    {
        planet1.velocity.x--;
        planet2.velocity.x++;
    }
    else
    {
        planet1.velocity.x++;
        planet2.velocity.x--;
    }
}

// Function to compare y axis and change the velocity
void compare_position_y(Planet &planet1, Planet &planet2)
{
    if (planet1.current_position.y > planet2.current_position.y)
    {
        planet1.velocity.y--;
        planet2.velocity.y++;
    }
    else
    {
        planet1.velocity.y++;
        planet2.velocity.y--;
    }
}

// Function to compare z axis and change the velocity
void compare_position_z(Planet &planet1, Planet &planet2)
{
    if (planet1.current_position.z > planet2.current_position.z)
    {
        planet1.velocity.z--;
        planet2.velocity.z++;
    }
    else
    {
        planet1.velocity.z++;
        planet2.velocity.z--;
    }
}

int calculate_orbital_period_x(std::vector<Planet> &planets)
{
    // Save the initial states for comparison (that they are back to the starting position)
    std::vector<Planet> initial_state_planets = planets;

    int time_steps{0};

    while (true)
    {
        // Compare the position of x and change the velocity
        compare_position_x(planets[0], planets[1]);
        compare_position_x(planets[0], planets[2]);
        compare_position_x(planets[0], planets[3]);
        compare_position_x(planets[0], planets[4]);
        compare_position_x(planets[1], planets[2]);
        compare_position_x(planets[1], planets[3]);
        compare_position_x(planets[1], planets[4]);
        compare_position_x(planets[2], planets[3]);
        compare_position_x(planets[2], planets[4]);
        compare_position_x(planets[3], planets[4]);

        // Update the position of x
        planets[0].current_position.x += planets[0].velocity.x;
        planets[1].current_position.x += planets[1].velocity.x;
        planets[2].current_position.x += planets[2].velocity.x;
        planets[3].current_position.x += planets[3].velocity.x;
        planets[4].current_position.x += planets[4].velocity.x;

        time_steps++;

        bool all_back_to_start{true};

        for (size_t i{0}; i < planets.size(); ++i)
        {
            // If not the same as starting position
            if (planets[i].current_position.x != initial_state_planets[i].current_position.x)
            {
                all_back_to_start = false;
                break;
            }
        }

        if (all_back_to_start)
        {
            break;
        }
    }

    return time_steps;
}

int calculate_orbital_period_y(std::vector<Planet> &planets)
{
    // Save the initial states for comparison (that they are back to the starting position)
    std::vector<Planet> initial_state_planets = planets;

    int time_steps{0};

    while (true)
    {
        // Compare the position of x and change the velocity
        compare_position_y(planets[0], planets[1]);
        compare_position_y(planets[0], planets[2]);
        compare_position_y(planets[0], planets[3]);
        compare_position_y(planets[0], planets[4]);
        compare_position_y(planets[1], planets[2]);
        compare_position_y(planets[1], planets[3]);
        compare_position_y(planets[1], planets[4]);
        compare_position_y(planets[2], planets[3]);
        compare_position_y(planets[2], planets[4]);
        compare_position_y(planets[3], planets[4]);

        // Update the position of x
        planets[0].current_position.y += planets[0].velocity.y;
        planets[1].current_position.y += planets[1].velocity.y;
        planets[2].current_position.y += planets[2].velocity.y;
        planets[3].current_position.y += planets[3].velocity.y;
        planets[4].current_position.y += planets[4].velocity.y;

        time_steps++;

        bool all_back_to_start{true};

        for (size_t i{0}; i < planets.size(); ++i)
        {
            // If not the same as starting position
            if (planets[i].current_position.y != initial_state_planets[i].current_position.y)
            {
                all_back_to_start = false;
                break;
            }
        }

        if (all_back_to_start)
        {
            break;
        }
    }

    return time_steps;
}

int calculate_orbital_period_z(std::vector<Planet> &planets)
{
    // Save the initial states for comparison (that they are back to the starting position)
    std::vector<Planet> initial_state_planets = planets;

    int time_steps{0};

    while (true)
    {
        // Compare the position of z and change the velocity
        compare_position_z(planets[0], planets[1]);
        compare_position_z(planets[0], planets[2]);
        compare_position_z(planets[0], planets[3]);
        compare_position_z(planets[0], planets[4]);
        compare_position_z(planets[1], planets[2]);
        compare_position_z(planets[1], planets[3]);
        compare_position_z(planets[1], planets[4]);
        compare_position_z(planets[2], planets[3]);
        compare_position_z(planets[2], planets[4]);
        compare_position_z(planets[3], planets[4]);

        // Update the position of z
        planets[0].current_position.z += planets[0].velocity.z;
        planets[1].current_position.z += planets[1].velocity.z;
        planets[2].current_position.z += planets[2].velocity.z;
        planets[3].current_position.z += planets[3].velocity.z;
        planets[4].current_position.z += planets[4].velocity.z;

        time_steps++;

        bool all_back_to_start{true};

        for (size_t i{0}; i < planets.size(); ++i)
        {
            // If not the same as starting position
            if (planets[i].current_position.z != initial_state_planets[i].current_position.z)
            {
                all_back_to_start = false;
                break;
            }
        }

        if (all_back_to_start)
        {
            break;
        }
    }

    return time_steps;
}
