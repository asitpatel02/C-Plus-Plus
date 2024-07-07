/*
Develop a program that draws a box that changes colour when it reaches the edge of the window.
Author: Asit Patel
*/

#include <simplecpp>

int main() {
    initCanvas("Color Changing Box", 800, 600);

    // Box properties
    Rectangle box(50, 50, 100, 100);
    box.setFill(true);
    box.setColor(COLOR("blue"));
    bool isBlue = true; // Flag to track the current color
    double boxSpeed = 5.0;

    // Main loop
    while (true) {
        // Move the box
        box.move(boxSpeed, 0);

        // Check if the box reaches the edge
        if (box.getX() <= 0 || box.getX() + box.getWidth() >= 800) {
            // Change the color of the box
            if (isBlue) {
                box.setColor(COLOR("red"));
                isBlue = false;
            } else {
                box.setColor(COLOR("blue"));
                isBlue = true;
            }

            // Reverse direction
            boxSpeed *= -1;
        }

        wait(0.02); // Delay for smooth movement
    }

    return 0;
}
