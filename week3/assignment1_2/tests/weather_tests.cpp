#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../includes/doctest.h"
#include "../includes/weather.hpp"

TEST_CASE("Test weather-library's functions") {
    
    SUBCASE("random number generating is working") {
        int num1{generate_random_value(0, 5)};
        CHECK(num1 >= 0);
        CHECK(num1 <= 5);
        int num2{generate_random_value(-28, 32)};
        CHECK(num2 >= -28);
        CHECK(num2 <= 32);
    }

    SUBCASE("generating weather readings is working") {
        // Temperature is +/- 3 degrees higher or lower than current
        // within realistic values (-94-64)
        int temp1{generate_temperature(25)};
        int temp2{generate_temperature(-95)};
        int temp3{generate_temperature(65)};
        CHECK(temp1 >= 22);
        CHECK(temp1 <= 28);
        CHECK(temp2 > -95);
        CHECK(temp2 <= -92);
        CHECK(temp3 >= 62);
        CHECK(temp3 < 65);
        // Humidy is +/- 10 % higher or lower than current
        // within realistic values (0-100)
        int hum1{generate_humidy(50)};
        int hum2{generate_humidy(0)};
        int hum3{generate_humidy(100)};
        CHECK(hum1 >= 40);
        CHECK(hum1 <= 60);
        CHECK(hum2 >= 0);
        CHECK(hum2 <= 10);
        CHECK(hum3 >= 90);
        CHECK(hum3 <= 100);
        // Wind speed is +/- 2 m/s higher or lower than current
        // within realistic values (0-113)
        int win1{generate_wind_speed(4)};
        int win2{generate_wind_speed(0)};
        int win3{generate_wind_speed(113)};
        CHECK(win1 >= 2);
        CHECK(win1 <= 6);
        CHECK(win2 >= 0);
        CHECK(win2 <= 2);
        CHECK(win3 >= 111);
        CHECK(win3 <= 113);
        // Pressure is +/- 2 hPa higher or lower than current
        // within realistic values (335-1013)
        int pres1{generate_pressure(900)};
        int pres2{generate_pressure(335)};
        int pres3{generate_pressure(1013)};
        CHECK(pres1 >= 898);
        CHECK(pres1 <= 902);
        CHECK(pres2 >= 335);
        CHECK(pres2 <= 337);
        CHECK(pres3 >= 1011);
        CHECK(pres3 <= 1013);
    }

    SUBCASE("check that users \"action choice\" is number") {
        CHECK(check_choice_is_valid(3) == 3);
        CHECK(check_choice_is_valid(1) == 1);
    }

    SUBCASE("writing and reading weather data works") {
        write_readings_into_file(10, 20, 30, 400);
        std::vector<std::string> previous_readings{read_previous_readings()};
        CHECK(previous_readings[0] == "10");
        CHECK(previous_readings[1] == "20");
        CHECK(previous_readings[2] == "30");
        CHECK(previous_readings[3] == "400");
    }


}