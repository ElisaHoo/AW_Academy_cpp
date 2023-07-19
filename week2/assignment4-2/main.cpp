/* Modbus communication
 * Modbus is a communication protocol for connecting electronic devices, 
 * allowing them to exchange data and be controlled by a central computer. 
 * In this exercise you are going to simulate a simple Modbus communication 
 * between one master device and a 10 slave devices. All the data will be 
 * stored in and read from files.
 * 
 * Exercise 1:
 * Every device has an unique id, is it master or slave device, and each 
 * slave device has a data register with the register address and a value 
 * for the register. Start by creating a program that generates the devices 
 * and stores them in a file called devices.csv (comma separated values) and 
 * another file called registers.csv that will store the slave devices id, 
 * register address and value.
 * 
 * Exercise 2:
 * Your program will simulate the master device reading a register from 
 * a slave device. Specify the slave device id, and register number, 
 * the program will then read the correct device and register, and print the 
 * register value.
 * 
 * Exercise 3:
 * Simulate the master writing a value into a slave device's register. Specify 
 * the id, register address and the new value. The program should update the value 
 * in the "register.txt" file.*/

#include "includes/file_handling.hpp"

int main() {
    std::vector<Device> devices_db;  // To store devices
    generate_devices(devices_db);
    write_devices_file(devices_db);
    write_register_file(devices_db);

    std::cout << "\nNext simulates master device reading a register from a slave device.\n";
    std::string address{get_specific_address()};  // Get register address number from user
    // get the value that corresponds to the address from registers
    std::string value{get_specific_register_value(address)};  
    std::cout << "The value corresponding to the register address is " << value << "\n";

    std::cout << "Next simulates master device writing into a slave device's register "
                 "(updating value).\n";
    /* Plan: first read all data into vector, 
     * second do the modification into vector, 
     * third overwrite modified data into file*/
    std::string address2{get_specific_address()};  // Get register address number from user
    std::string new_value{"0.089"};  // a new value the master will write to register
    std::vector<std::string> original_file_data = push_file_data_into_vector();
    std::vector<std::string> modified_file_data = modify_specific_value(
        original_file_data, 
        address2, 
        new_value);
    overwrite_file_with_modified_data(modified_file_data);

    return 0;
}