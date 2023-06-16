#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

struct SensorData {
    std::string sensor_id;
    long int timestamp;
    float sensor_value;
};

inline std::vector<SensorData> sensor_data_list;

long int generate_timestamp();
std::string generate_id();
float generate_sensor_value();
void generate_sensor_data(SensorData sensor_data);
std::vector<SensorData> filter_specified_sensor_data(SensorData sensor_data, std::string specified_id);
bool compare_timestamps(const SensorData& first, const SensorData& second);
void sort_data_based_on_timestamp(std::vector<SensorData>& specified_sensor_data_list);
void print_data(std::vector<SensorData> data_vector);
void detect_outliers();
void find_sensor_with_highest_frequency_of_readings(std::vector<SensorData>& v, SensorData);

#endif