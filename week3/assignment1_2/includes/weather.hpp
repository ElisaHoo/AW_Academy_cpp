#ifndef WEATHER_HPP
#define WEATHER_HPP

#include <iostream>
#include <random>
#include <vector>
#include <filesystem>
#include <fstream>
#include <sstream>

int generate_random_value(int starting_value, int ending_value);

int generate_temperature(int previous_temp);

int generate_humidy(int previous_humidy);

int generate_wind_speed(int previous_wind_speed);

int generate_pressure(int previous_pressure);

int check_choice_is_valid(int choice);

void clear_failed_cin();

std::vector<std::string> read_all_weather_data();

std::vector<std::string> read_previous_readings();

void write_readings_into_file(int temperature, int humidy, int wind_speed, int pressure);

bool check_temperature_is_valid(int temperature);

bool check_humidy_is_valid(int humidy);

bool check_wind_speed_is_valid(int speed);

bool check_pressure_is_valid(int pressure);

#endif