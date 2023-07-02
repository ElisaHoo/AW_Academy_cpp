#include <iostream>
#include <vector>
#include <algorithm>

/* You are teaching a programming course and you have many exercises 
 * that require peer reviews. The system that is hosting these 
 * exercises has broken and the automatic peer review assignment is 
 * not working. Write a program that lists all the students, and when 
 * the program gets run it will automatically create a peer review list 
 * where every student gets to review someone else's exercise. 
 * Each student will review another person and two students can't 
 * review each others assignments.*/

void rotate_students(std::vector<std::string> group1, std::vector<std::string> group2, std::vector<std::pair<std::string, std::string>> peer_pairs);


int main() {
    /// Vector of all students
    std::vector<std::string> students{"Roope", "Pluto", "Hessu", "Heluna", 
                                      "Mikki", "Aku", "Minni", "Iines"};
    
    // Split the students into two groups
    std::vector<std::string> group1(students.begin(), students.begin() + students.size() / 2);
    std::vector<std::string> group2(students.begin() + students.size() / 2, students.end());

    // Vector of pairs for listing who is peer-reviewing who
    std::vector<std::pair<std::string, std::string>> peer_pairs;

    // Defining who group 1 will review...
    for (int i = 0; i < group1.size(); ++i) {
        peer_pairs.push_back(std::make_pair(group1[i], group2[i]));
    }

    std::cout << "Peer reviews are done as follows:\n";
    
    // ... and printing these out
    for (int i = 0; i < peer_pairs.size(); ++i) {
        std::cout << peer_pairs[i].first << " reviews " << peer_pairs[i].second << "\n";
    }

    // Rotating the group 1 by one (to avoid two students reviewing each others assignments)
    rotate_students(group1, group2, peer_pairs);

    return 0;
}

void rotate_students(std::vector<std::string> group1, std::vector<std::string> group2, std::vector<std::pair<std::string, std::string>> peer_pairs) {
    std::rotate(group1.begin(), group1.begin() + 1, group1.end());

    // Defining who group 2 will review ...
    for (int i = 0; i < group1.size(); ++i) {
        peer_pairs.push_back(std::make_pair(group2[i], group1[i]));
    }
    
    // ...and printing these out
    for (int i = peer_pairs.size() / 2; i < peer_pairs.size(); ++i) {
        std::cout << peer_pairs[i].first << " reviews " << peer_pairs[i].second << "\n";
    }
    std::cout << "\n";
}