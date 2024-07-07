#include <simplecpp>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Represents a student.
 * 
 * This struct represents a student and contains information such as their ID, name, age, and grade.
 */
struct Student {
    int id;
    string name;
    int age;
    float grade;
};

/**
 * @brief Takes user input to populate the details of a Student object.
 * 
 * @param student The Student object to be populated with user input.
 */
void inputStudentDetails(Student &student) {
    cout << "Enter student ID: ";
    cin >> student.id;
    cout << "Enter student name: ";
    cin.ignore(); // Ignore newline character in buffer
    getline(cin, student.name);
    cout << "Enter student age: ";
    cin >> student.age;
    cout << "Enter student grade: ";
    cin >> student.grade;
}

/**
 * Displays the details of a student.
 * 
 * @param student The student object whose details are to be displayed.
 */
void displayStudentDetails(const Student &student) {
    cout << "Student ID: " << student.id << endl;
    cout << "Name: " << student.name << endl;
    cout << "Age: " << student.age << endl;
    cout << "Grade: " << student.grade << endl;
}

/**
 * Calculates and displays the average grade of a vector of Student objects.
 * 
 * @param students A constant reference to a vector of Student objects.
 *                 The vector should contain the student records for which the average grade needs to be calculated.
 * 
 * @return None.
 * 
 * @note If the vector is empty, the function will display a message indicating that there are no students to calculate the average grade.
 */
void calculateAndDisplayAverageGrade(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No students to calculate average grade." << endl;
        return;
    }

    float totalGrade = 0;
    for (const auto &student : students) {
        totalGrade += student.grade;
    }
    float averageGrade = totalGrade / students.size();
    cout << "Average grade of all students: " << averageGrade << endl;
}

/**
 * Searches for a student with the given ID in the vector of students and displays their details.
 * If no student with the given ID is found, a message is displayed.
 *
 * @param students The vector of students to search.
 * @param id The ID of the student to search for.
 */
void searchAndDisplayStudentByID(const vector<Student> &students, int id) {
    if (students.empty()) {
        cout << "No students to search." << endl;
        return;
    }

    bool found = false;
    for (const auto &student : students) {
        if (student.id == id) {
            displayStudentDetails(student);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID " << id << " not found." << endl;
    }
}

/**
 * @brief The main function of the program.
 *
 * This function serves as the entry point of the program. It contains a menu-driven loop that allows the user to perform various operations on a collection of student records.
 *
 * @return int The exit status of the program.
 */
int main() {
    vector<Student> students;
    char choice;

    do {
        cout << "\nOptions:\n";
        cout << "1. Input student details\n";
        cout << "2. Display student details\n";
        cout << "3. Calculate and display the average grade of all students\n";
        cout << "4. Search for a student by ID and display their details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch(choice) {
            case '1': {
                do {
                    Student newStudent;
                    inputStudentDetails(newStudent);
                    students.push_back(newStudent);
                    char addMore;
                    cout << "Do you want to add more student information? (y/n): ";
                    cin >> addMore;
                    if (addMore != 'y' && addMore != 'Y')
                        break; // Exit the do-while loop
                    else
                        cin.ignore(); // Clear newline character from buffer
                } while (true);
            }
            break;
            case '2':
                cout << "\n----- Student Details -----\n";
                for (const auto &student : students) {
                    displayStudentDetails(student);
                    cout << endl;
                }
                break;
            case '3':
                calculateAndDisplayAverageGrade(students);
                break;
            case '4':
                do {
                    int searchID;
                    cout << "\nEnter the ID of the student you want to search: ";
                    cin >> searchID;
                    searchAndDisplayStudentByID(students, searchID);
                    char searchMore;
                    cout << "Do you want to search another student? (y/n): ";
                    cin >> searchMore;
                    if (searchMore != 'y' && searchMore != 'Y')
                        break; // Exit the do-while loop
                } while (true);
                break;
            case '5':
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (true);

    return 0;
}
