#include <iostream>
#include <vector>
#include <string>
#include <numeric>

/* 
 * Create a student database program. The program will ask the user 
 * for how many students the user wants to input. For each student 
 * the program will store the students name, age and grade.
 * The program will then print out the average grade of the class 
 * and the student with the highest grade.
 * */

// Create student-struct
struct student {
    std::string name;
    int age;
    int grade;
};

// Ask how many students
int get_number_of_students() {
    std::cout << "Please enter how many students you want to input: ";
    int amount{};
    std::cin >> amount;
    return amount;
}

// Get students name, age and grade
std::vector<student> get_students_data(int number_of_students) {
    std::vector<student> students(number_of_students);

    for (int i = 0; i < number_of_students; i++) {
        std::cout << "Enter student's information\n";
        std::cout << "Name: ";
        std::cin >> students[i].name;
        std::cout << "Age: ";
        std::cin >> students[i].age;
        std::cout << "Grade: ";
        std::cin >> students[i].grade;
    }

    return students;
}

// Get average grade of the class
double get_average_grade(std::vector<student> students_data, int number_of_students) {
    // get grades
    std::vector<int> grades{};
    for (int i = 0; i < number_of_students; i++) {
        grades.push_back(students_data[i].grade);
    }
    // count and return average grade
    double sum_of_grades{std::accumulate(grades.begin(), grades.end(), 0.0)};
    return (sum_of_grades / grades.size());
}

// Get the student with the highest grade
std::string get_highest_grade(std::vector<student> students_data, int number_of_students) {
    int highest_grade{0};
    std::string students_name{};
    for (int i = 0; i < number_of_students; i++) {
        if (students_data[i].grade > highest_grade) {
            students_name = students_data[i].name;
            highest_grade = students_data[i].grade;
        }
    }
    return students_name;
}

int main() {
    int number_of_students{get_number_of_students()};
    std::vector<student> students_data{get_students_data(number_of_students)};
    std::cout << "The average grade of the class is " << get_average_grade(students_data, number_of_students) << "\n";
    std::cout << "Student who has the highest grade is " << get_highest_grade(students_data, number_of_students) << "\n";

    return 0;
}