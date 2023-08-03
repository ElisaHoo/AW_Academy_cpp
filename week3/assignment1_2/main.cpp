/* Your task is to create a virtual weather station. The program should handle 
 * any exceptions that may occur during runtime. Handle various aspects like 
 * temperature, humidity, wind speed and atmospheric pressure.
 * Generate weather data via a function simulating changes in weather over time. 
 * Make sure the data changes in a way that's somewhat realistic. So the temperature 
 * should not jump from +20C to -20C. Implement exception handling. If data 
 * generated is out of logical range for example the temperature is less than 
 * -273.15C or humidity is over 100%. Log data in files. Handle any file-related 
 * exceptions like not being able to open the file. The console applications 
 * should be able to show logs and current weather. For testing purposes you can 
 * add a function that allows you to manually add weather readings.*/

#include "includes/weather.hpp"

int main()
{
    std::cout << "\n** Virtual Weather Station **\n";
    // UI
    while (true) {
        std::cout << "\nPlease choose an action:\n";
        std::cout << "(1) Generate current weather readings\n";
        std::cout << "(2) View past weather readings\n";
        std::cout << "(3) Add weather readings manually (for testing purposes)\n";
        std::cout << "(4) Exit\n";
        int choice{};
        std::cin >> choice;
        int valid_choice{check_choice_is_valid(choice)};

        switch (valid_choice)
        {
        case 1:  // Generate new readings
            {
                int new_temperature{};
                int new_humidy{};
                int new_wind_speed{};
                int new_pressure{};

                // Get the previous weather readings
                std::vector<std::string> previous_readings{read_previous_readings()};
                
                // If there is no previous data, generate data randomly within the limits 
                // given as attributes
                if (previous_readings.size() == 0) {
                    new_temperature = generate_random_value(-28, 30);
                    new_humidy = generate_random_value(10, 98);
                    new_wind_speed = generate_random_value(5, 10);
                    new_pressure = generate_random_value(990, 995);
                
                } else {
                    // If there is previous data, use it as a base to generate "realistic data"
                    new_temperature = generate_temperature(std::stoi(previous_readings[0]));
                    new_humidy = generate_humidy(std::stoi(previous_readings[1]));
                    new_wind_speed = generate_wind_speed(std::stoi(previous_readings[2]));
                    new_pressure = generate_pressure(std::stoi(previous_readings[3]));
                }
                
                // Print the new readings out
                std::cout << "\nThe current weather readings are:\n" 
                             "Temperature " << new_temperature << " degrees Celsius\n"
                             "Humidy " << new_humidy << " %\n"
                             "Wind speed " << new_wind_speed << " m/s\n"
                             "Atmospheric pressure " << new_pressure << " hPa.\n";
                
                // Write the new readings into end of the file
                write_readings_into_file(new_temperature, new_humidy, new_wind_speed, new_pressure);
            }
            break;
        
        case 2:  // Show logs
            {
                // Get all file data into vector
                std::vector<std::string> file_data{read_all_weather_data()};
                // If there is no previous data, show message and break out
                if (file_data.size() <= 1) {
                    std::cout << "\nThere is no previous data to view!\n";
                    break;
                }
                // If there is previous data, first print header line
                std::cout << "\ntemp\thumidy\tw.speed\tatmosph.pressure\n";
                // And after that, each reading on its own line
                for (int i = 0; i < file_data.size(); ++i) {
                    if (i % 4  == 0 && i != 0) {
                        std::cout << "\n";  // print new line after every 4th value
                        std::cout << file_data[i] << "\t";
                    } else if (i == file_data.size() -1) {
                        std::cout << file_data[i] << "\n";  // print new line after last value
                    } else {
                        std::cout << file_data[i] << "\t";  // In other cases, print intendation/tab
                    }
                }
            }
            break;

        case 3:  /*Add readings manually. Get the input from the user, test if it's valid and if not,
                   ask enter it again. When all the values are valid, save the values into file.*/
            {
                std::string temperature{};
                while (true) {
                    std::cout << "Enter the new temperature (Celcius): ";
                    std::getline(std::cin >> std::ws, temperature);
                    try {
                        if (!check_temperature_is_valid(std::stoi(temperature))) {
                        std::cout << "\nThe coldest temperature ever measured on Earth "
                                 "was approx -90 Celcius and hottest approx 58 Celcius. "
                                 "Please enter value between -95 and 65.\n";
                        continue;
                        }
                        break;
                    }
                    // Catch if user tries to input something other than integer (stoi is not possible)
                    catch(const std::exception& e) {
                        std::cout << "\nInvalid input! Please enter an integer!\n";
                        continue;
                    }
                }

                std::string humidy{};
                while (true) {
                    std::cout << "Enter the new humidy (%): ";
                    std::getline(std::cin >> std::ws, humidy);
                    try {
                        if (!check_humidy_is_valid(std::stoi(humidy))) {
                        std::cout << "\nHumidy must be 0-100%. Please try again.\n";
                        continue;
                        }
                        break;
                    }
                    // Catch if user tries to input something other than integer (stoi is not possible)
                    catch(const std::exception& e) {
                        std::cout << "\nInvalid input! Please enter an integer!\n";
                        continue;
                    }
                }

                std::string wind_speed{};
                while (true) {
                    std::cout << "Enter the new wind speed (m/s): ";
                    std::getline(std::cin >> std::ws, wind_speed);
                    try {
                        if (!check_wind_speed_is_valid(std::stoi(wind_speed))) {
                        std::cout << "\nThe fastest wind speed measured in earth was approx 113 m/s "
                                     "(if tornadoes not included). Please enter a value between 0 and 113.\n";
                        continue;
                        }
                        break;
                    }
                    // Catch if user tries to input something other than integer (stoi is not possible)
                    catch(const std::exception& e) {
                        std::cout << "\nInvalid input! Please enter an integer!\n";
                        continue;
                    }
                }

                std::string pressure{};
                while (true) {
                    std::cout << "Enter the new pressure (hPa): ";
                    std::getline(std::cin >> std::ws, pressure);
                    try {
                        if (!check_pressure_is_valid(std::stoi(pressure))) {
                        std::cout << "\nPressure must be between 335 hPa (Mount Everest) and 1013 hPa (sea level)."
                                     " Please try again.\n";
                        continue;
                        }
                        break;
                    }
                    // Catch if user tries to input something other than integer (stoi is not possible)
                    catch(const std::exception& e) {
                        std::cout << "\nInvalid input! Please enter an integer!\n";
                        continue;
                    }
                }
                write_readings_into_file(
                        std::stoi(temperature), 
                        std::stoi(humidy), 
                        std::stoi(wind_speed), 
                        std::stoi(pressure)
                );       
            }
            break;
        
        case 4:  // Exit
            {
                std::cout << "\nGoodbye!\n\n";
                return 0;
            }       
        default:
            std::cout << "\nPlease choose an action from numbers 1-4!\n";
            break;
        }
    }
}