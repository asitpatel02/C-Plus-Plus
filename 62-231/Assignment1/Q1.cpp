/*
1. Bouncing Ball Animation
• Create a program that animates a circle (representing a ball) that continuously bounces between the edges of the window. The ball should reverse its direction upon touching an edge.
• Utilize a while loop to keep the animation running indefinitely.
• Use if statements to check for collisions with the window edges.
*/

#include <simplecpp>

int main() {
    // Set up the graphics window
    initCanvas("Bouncing Ball", 800, 600);

    // Initialize variables for ball position, radius, and velocity
    double x = canvas_width() / 2;
    double y = canvas_height() / 2;
    double radius = 20;
    double dx = 5; // velocity in x direction
    double dy = 5; // velocity in y direction

    // Draw the ball
    Circle ball(x, y, radius);
    ball.setFill(true);
    ball.setColor(COLOR("blue"));

    // Main animation loop
    while (true) {
        // Move the ball
        ball.move(dx, dy);

        // Check for collisions with window edges
        if (ball.getX() - radius <= 0 || ball.getX() + radius >= canvas_width()) {
            dx = -dx; // Reverse velocity in x direction
        }
        if (ball.getY() - radius <= 0 || ball.getY() + radius >= canvas_height()) {
            dy = -dy; // Reverse velocity in y direction
        }

        // Wait for a short time to control animation speed
        wait(0.05);
    }

    // The program never reaches this point because the animation runs indefinitely

    return 0;
}
