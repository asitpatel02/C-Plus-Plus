#include <simplecpp>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Error: Division by zero is not allowed.");
    }
    return a / b;
}

int main() {
    string operation;
    double num1, num2;

    cout << "Enter the operation (A = Addition, S = Subtraction, M = Multiplication, D = Division): ";
    cin >> operation;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    double result;
    try {
        if (operation == "A") {
            result = add(num1, num2);
        } else if (operation == "S") {
            result = subtract(num1, num2);
        } else if (operation == "M") {
            result = multiply(num1, num2);
        } else if (operation == "D") {
            result = divide(num1, num2);
        } else {
            throw runtime_error("Error: Invalid operation.");
        }

        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
