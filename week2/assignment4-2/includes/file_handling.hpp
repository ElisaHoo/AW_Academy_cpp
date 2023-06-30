#ifndef FILE_HANDLING_HPP
#define FILE_HANDLING_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <sstream>

struct DataRegister
{
    int address;
    int value;
};

struct Device
{
    int id;
    bool is_master;
    DataRegister register_db;
};

int generate_random_value();
std::vector<DataRegister> generate_register();
void generate_devices(std::vector<Device>& devices_db);
void write_devices_file(std::vector<Device> devices_db);
void write_register_file(std::vector<Device> devices_db);
void clear_failed_cin();
std::string get_specific_address();
std::string get_specific_register_value(std::string address);
std::vector<std::string> push_file_data_into_vector();
std::vector<std::string> modify_specific_value(std::vector<std::string> file_data, std::string address, std::string new_value);
void overwrite_file_with_modified_data(std::vector<std::string> file_data);

#endif