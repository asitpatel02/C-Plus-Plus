/*
Create a simple program to draw a box that moves across the screen.
Author: Asit Patel
*/

#include <simplecpp>

int main() {
    initCanvas("Moving Box", 800, 600);

    // Box properties
    Rectangle box(25, 25, 50, 50);
    box.setFill(true);
    box.setColor(COLOR("black"));
    double boxSpeed = 5.0;


    while (true) {

        XEvent event;
        if (checkEvent(event)) {
            if (keyPressEvent(event)) {
                char key = charFromEvent(event);
                if (key == 'a') {
                    box.move(-boxSpeed, 0); // Move left
                } else if (key == 'd') {
                    box.move(boxSpeed, 0); // Move right
                } else if (key == 'w') {
                    box.move(0, -boxSpeed); // Move up
                } else if (key == 's') {
                    box.move(0, boxSpeed); // Move down
                }
            }
        }

        // Boundary check for the box
        if (box.getX() < 0)
            box.moveTo(0, box.getY());
        if (box.getX() + box.getWidth() > 800)
            box.moveTo(800 - box.getWidth(), box.getY());
        if (box.getY() < 0)
            box.moveTo(box.getX(), 0);
        if (box.getY() + box.getHeight() > 600)
            box.moveTo(box.getX(), 600 - box.getHeight());

        wait(0.02); // Delay for smooth movement
    }

    return 0;
}
