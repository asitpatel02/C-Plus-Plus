/*
5. Interactive Rectangle Resizing
• Develop a program that displays a rectangle. The rectangle should grow wider if the user presses the "W" key and narrower if the "N" key is pressed.
• Implement an event listener for key presses and use if statements to determine if the "W" or "N" key was pressed.
• Use a while loop to keep the program running, allowing continuous adjustment of the rectangle's width.
*/

#include <simplecpp>
#include <iostream>

int main() {
    // Set initial width and height of the rectangle
    double width = 70;
    double height = 70;

    // Create a canvas to draw on
    initCanvas("Rectangle Resizing", 500, 400);

    // Draw the initial rectangle
    Rectangle rect(250, 200, width, height);
    rect.setFill(true);
    rect.setColor(COLOR("blue"));
    rect.imprint();

    // Display instructions
    Text instructions(250, 20, "Press 'W' to widen, 'N' to narrow, 'L' to lengthen, 'S' to shorten the rectangle.");

    // Event loop to listen for key presses
    while (true) {
        char key;
        cin >> key; // Read the key from standard input

        // Check if 'W' key is pressed to widen the rectangle
        if (key == 'w' || key == 'W') {
            width += 10; // Increase width
            rect.reset(250, 200, width, height); // Reset rectangle with new width
        }
        // Check if 'N' key is pressed to narrow the rectangle
        else if (key == 'n' || key == 'N') {
            width -= 10; // Decrease width
            // Ensure width doesn't become negative
            if (width < 10) {
                width = 10;
            }
            rect.reset(250, 200, width, height); // Reset rectangle with new width
        }
        // Check if 'L' key is pressed to lengthen the rectangle
        else if (key == 'l' || key == 'L') {
            height += 10; // Increase height
            rect.reset(250, 200, width, height); // Reset rectangle with new height
        }
        // Check if 'S' key is pressed to shorten the rectangle
        else if (key == 's' || key == 'S') {
            height -= 10; // Decrease height
            // Ensure height doesn't become less than a minimum value
            if (height < 10) {
                height = 10; // Set minimum height
            }
            rect.reset(250, 200, width, height); // Reset rectangle with new height
        }
        // If none of the valid keys are pressed, display an error message
        else {
            cout << "Invalid key pressed. Please enter 'W', 'N', 'L', or 'S'." << endl;
        }
    }

    // Close the graphics window
    closeCanvas();
    return 0;
}
