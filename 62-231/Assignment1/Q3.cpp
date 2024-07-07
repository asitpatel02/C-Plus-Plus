/*
3. Moving Across Grid
• Create a grid of squares on the screen. Animate a circle that moves across the grid, changing direction randomly at each intersection.
• Use a while loop to keep the circle moving, and if statements to change its direction at grid intersections.
• Incorporate a random choice mechanism to decide the circle's next direction at each intersection.
*/

#include <simplecpp>
#include <iostream>

int main() {
    const int gridSize = 10; // Number of squares in one dimension
    const int canvasSize = gridSize * 50; // Size of the canvas
    initCanvas("Grid", canvasSize, canvasSize); // create a canvas of size 500x500

    // Draw the grid
    for(int i = 0; i <= gridSize; i++) {
        line(0, i * 50, canvasSize, i * 50); // draw horizontal lines
        line(i * 50, 0, i * 50, canvasSize); // draw vertical lines
    }

    Circle c(canvasSize / 1, canvasSize / 1, 20); // create a circle at the center of the grid with radius 10
    c.setColor(COLOR("red")); // set the color of the circle to red
    c.setFill(true); // fill the circle with the color

    while(true) { // loop forever
        wait(0.5); // wait for 0.5 seconds

        // Generate random movement within canvas bounds
        double dx = (randuv(-1, 1) - 0.5) * 50; // generate a random number between -25 and 25 for dx
        double dy = (randuv(-1, 1) - 0.5) * 50; // generate a random number between -25 and 25 for dy

        // Calculate new position aligned with grid lines
        double x = c.getX() + dx; // calculate new x position
        double y = c.getY() + dy; // calculate new y position
        x = round(x / 50) * 50; // round x to the nearest multiple of 50
        y = round(y / 50) * 50; // round y to the nearest multiple of 50

        // Ensure the circle stays within canvas bounds
        x = max(10.0, min(canvasSize - 10.0, x)); // ensure x stays within canvas bounds
        y = max(10.0, min(canvasSize - 10.0, y)); // ensure y stays within canvas bounds

        // Move the circle
        c.moveTo(x, y); // move the circle to the new position

        // Output the coordinates to the command line
        cout << "Circle coordinates: (" << x << ", " << y << ")" << endl;
    }

    return 0;
}
