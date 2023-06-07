#include <iostream>

int convert_to_minutes(int time);

int main() {
    std::cout << "Please enter starting time (hhmm): ";
    int starting{};
    std::cin >> starting;

    std::cout << "Please enter ending time (hhmm): ";
    int ending{};
    std::cin >> ending;

    int time_difference_min = convert_to_minutes(ending) - convert_to_minutes(starting);

    std::cout << "Time difference is " << (time_difference_min / 60) << " hours and " << (time_difference_min % 60) << " minutes\n";

    return 0;
}

int convert_to_minutes(int time) {
    // (time / 100 * 60) converts hours to minutes and (time % 100)
    // gets the leftover minutes
    int minutes = time / 100 * 60 + time % 100;   
    return minutes;
}