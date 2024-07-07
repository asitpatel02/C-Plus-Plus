#include <simplecpp>

int main() {
    const int NUM_STUDENTS = 10;
    const int NUM_TESTS = 5;

    int M[NUM_STUDENTS][NUM_TESTS];

    // Read marks from the user
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter marks for student " << i + 1 << ": ";
        for (int j = 0; j < NUM_TESTS; j++) {
            cin >> M[i][j];
        }
    }

    // Print the marks
    cout << "Marks of the students:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < NUM_TESTS; j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}