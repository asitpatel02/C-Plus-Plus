#include <iostream>
#include <vector>

struct Student {
    int rollNumber;
    int marks;
};

int main() {
    std::vector<Student> students(100);

    // Read in marks of the 100 students in roll number order
    for (int i = 0; i < 100; i++) {
        students[i].rollNumber = i;
        std::cout << "Enter marks for student with roll number " << i << ": ";
        std::cin >> students[i].marks;
    }

    // Process queries for individual students
    while (true) {
        int rollNumber;
        std::cout << "Enter roll number of student (-1 to exit): ";
        std::cin >> rollNumber;

        if (rollNumber == -1) {
            break;
        }

        // Find the student with the given roll number
        bool found = false;
        for (const auto& student : students) {
            if (student.rollNumber == rollNumber) {
                std::cout << "Marks for student with roll number " << rollNumber << ": " << student.marks << std::endl;
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
        }
    }

    return 0;
}
