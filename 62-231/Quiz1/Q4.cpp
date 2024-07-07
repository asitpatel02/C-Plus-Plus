/*
Create an interactive program where a circle changes size based on keyboard input, and a square move based on mouse movement.
Author: Asit Patel
*/
#include <simplecpp>

int main() {
    initCanvas("Interactive Program", 800, 600);

    Circle circle(400, 300, 50);
    Rectangle square(400, 300, 50, 50);

    double circleRadius = 50;

    while (true) {
        char key;
        cin >> key;

        if (key == 'q') {
            break;
        } else if (key == 'a') {
            circleRadius += 5;
        } else if (key == 's') {
            circleRadius -= 5;
            if (circleRadius < 5) circleRadius = 5;
        }

        circle.reset(400, 300, circleRadius);

        int mouseX, mouseY;
        getClick(mouseX, mouseY); // Capture mouse click event

        square.reset(mouseX - 25, mouseY - 25, 50, 50);

        // Uncomment the line below to clear the canvas on each iteration
        // clearCanvas();
    }

    closeCanvas();
    return 0;
}
