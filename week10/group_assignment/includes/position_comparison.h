#ifndef POSITION_COMPARISON_H
#define POSITION_COMPARISON_H

#include "planet.h"

#include <vector>
#include <iostream>

// Function to compare x axis and change the velocity
void compare_position_x(Planet &planet1, Planet &planet2);

// Function to compare y axis and change the velocity
void compare_position_y(Planet &planet1, Planet &planet2);

// Function to compare z axis and change the velocity
void compare_position_z(Planet &planet1, Planet &planet2);

// Function to calculate the orbital period for x axis
int calculate_orbital_period_x(std::vector<Planet> &planets);

// Function to calculate the orbital period for y axis
int calculate_orbital_period_y(std::vector<Planet> &planets);

// Function to calculate the orbital period for z axis
int calculate_orbital_period_z(std::vector<Planet> &planets);

#endif
