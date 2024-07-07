/*
2. Dynamic Square Spiral
• Write a program to draw a square spiral where each square's side length increases incrementally. Start from the center of the window and work outward.
• Implement this using a for loop, with the number of iterations determining the size of the spiral.
• Adjust the side length after each complete square to create the spiral effect.
*/

#include <simplecpp>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Function to generate a random color
Color getRandomColor() {
    int r = rand() % 256; // Random red component
    int g = rand() % 256; // Random green component
    int b = rand() % 256; // Random blue component
    return COLOR(r, g, b);
}

int main() {
    // Set up the graphics canvas
    initCanvas("Square Spiral", 800, 800);

    // Set initial position and side length
    double x = getmaxx() / 2;
    double y = getmaxy() / 2;
    double sideLength = 10;

    // Seed the random number generator
    simplecpp::srand(time(NULL));

    // Draw the spiral
    for (int i = 0; i < 50; i++) {  // Adjust the number of iterations as needed
        // Draw a square with each side a random color
        Rectangle square(x - sideLength / 2, y - sideLength / 2, sideLength, sideLength);
        square.setColor(COLOR("black"));  // Set border color
        square.setFill(false);             // Do not fill color inside the square
        square.imprint();                  // Draw on canvas

        // Draw a filled rectangle to fill the color inside the square
        Rectangle fillRect(x - sideLength / 2 + 1, y - sideLength / 2 + 1, sideLength - 2, sideLength - 2);
        fillRect.setColor(getRandomColor());  // Set fill color
        fillRect.setFill(true);                // Fill color inside the square
        fillRect.imprint();                    // Draw on canvas

        wait(0.2);                         // Pause for visualization

        // Update position for the next square
        x += sideLength / 2;
        y += sideLength / 2;

        // Increase side length for the next square
        sideLength += 10;

        // Draw next square with each side a different random color
        for (int j = 0; j < 4; j++) {
            // Draw each side of the square with a random color
            Line side(x - sideLength / 2, y - sideLength / 2, x + sideLength / 2, y - sideLength / 2);
            side.setColor(getRandomColor());
            side.imprint();
            wait(0.1);

            side.reset(x + sideLength / 2, y - sideLength / 2, x + sideLength / 2, y + sideLength / 2);
            side.setColor(getRandomColor());
            side.imprint();
            wait(0.1);

            side.reset(x + sideLength / 2, y + sideLength / 2, x - sideLength / 2, y + sideLength / 2);
            side.setColor(getRandomColor());
            side.imprint();
            wait(0.1);

            side.reset(x - sideLength / 2, y + sideLength / 2, x - sideLength / 2, y - sideLength / 2);
            side.setColor(getRandomColor());
            side.imprint();
            wait(0.1);

            // Update position for the next side
            x += sideLength * cos(j * 3.14159 / 2); // Using manual definition of pi
            y += sideLength * sin(j * 3.14159 / 2);
        }
    }

    // Wait for a click before closing the window
    getClick();

    return 0;
}
