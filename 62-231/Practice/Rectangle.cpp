#include <iostream>

int main() {
    // Input coordinates (X, Y)
    double X, Y;

    // Prompt the user for input
    std::cout << "Enter the X coordinate: ";
    std::cin >> X;

    std::cout << "Enter the Y coordinate: ";
    std::cin >> Y;

    // Check if the point is inside the rectangle
    if (X >= 0 && X <= 10 && Y >= 50 && Y <= 70) {
        std::cout << "The point (" << X << ", " << Y << ") is inside the rectangle." << std::endl;
    } else {
        std::cout << "The point (" << X << ", " << Y << ") is outside the rectangle." << std::endl;
    }

    return 0;
}
