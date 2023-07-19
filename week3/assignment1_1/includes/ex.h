#ifndef EX_H
#define EX_H
#include <iostream>
#include <vector>
#include <algorithm>

const int ERROR_CODE{1};

float division(float num1, float num2);
int find_maximum_value(std::vector<int> numbers);
void choose_name(std::vector<std::string> names);
void process_data(int number);
void process_data(std::string str);

#endif