/*
Write a program to draw a circle and animate it moving in a vertical line.
Author: Asit Patel
*/

#include <simplecpp>

int main() {
    initCanvas("Moving Circle", 800, 600);

    // Circle properties
    Circle circle(400, 50, 25);
    circle.setFill(true);
    circle.setColor(COLOR("red"));
    double circleSpeed = 4.0;

    // Main loop
    while (true) {
        // Move the circle
        circle.move(0, circleSpeed);

        // Reverse direction if the circle reaches the top or bottom edge
        if (circle.getY() <= circle.getRadius() || circle.getY() >= 600 - circle.getRadius())
            circleSpeed *= -1;

        wait(0.02); // Delay for smooth movement
    }

    return 0;
}
