/* In an industrial setting, various sensors are used to monitor equipment health, 
 * environmental conditions, etc. Suppose you are receiving sensor data that 
 * includes a timestamp, sensor ID, and the sensor reading.
 * Exercise 1:
 * Develop a function to simulate data ingestion. This function should generate 
 * a list of sensor readings. Each reading is an object that includes a timestamp 
 * (use integers for simplicity), a sensor ID (string), and a sensor value (float).
 * Exercise 2:
 * Implement a function that accepts the sensor data list and a sensor ID as 
 * parameters. This function should filter out the readings from the specified 
 * sensor and return them as a new list.
 * Exercise 3:
 * Develop a function that sorts the filtered sensor data based on the timestamp 
 * in ascending order. This can help in understanding the time series behavior of 
 * a particular sensor.
 * Exercise 4.
 * Develop a function to detect outliers in sensor readings. An outlier can be 
 * defined as a value that deviates by more than a fixed amount from the mean 
 * sensor value.
 * Exercise 5:
 * Develop a function to find the sensor that has the highest frequency of readings. 
 * This might indicate that this sensor's data is crucial or the equipment it's 
 * monitoring is critical.*/

#include "includes/sensor.h"

int main() {
    SensorData sensor_data;
    // Exercise 1. generate a list of sensor readings
    generate_sensor_data(sensor_data);
    
    // Exercise 2. filter out the readings from the specified sensor and return them as a new list
    std::vector<SensorData> specified_sensor_data_list = filter_specified_sensor_data 
                            (sensor_data, sensor_data_list[5].sensor_id);
    std::cout << "\nSpecified sensor data:\n";
    print_data(specified_sensor_data_list);
    
    // Exercise 3. sort the filtered sensor data based on the timestamp in ascending order
    sort_data_based_on_timestamp(specified_sensor_data_list);
    std::cout << "\nSorted sensor data:\n";
    print_data(specified_sensor_data_list);

    // Exercise 4. to detect outliers in sensor readings
    detect_outliers();

    // Exercise 5. to find the sensor that has the highest frequency of readings
    find_sensor_with_highest_frequency_of_readings(sensor_data_list, sensor_data);

    return 0;
}