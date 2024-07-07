#include <simplecpp>

using namespace std;
using namespace simplecpp;

/**
 * @class MyRectangle
 * @brief Represents a rectangle with a given length and width.
 */
class MyRectangle {
private:
    float length; /**< The length of the rectangle. */
    float width; /**< The width of the rectangle. */

public:
    /**
     * @brief Constructor for MyRectangle.
     * @param l The length of the rectangle.
     * @param w The width of the rectangle.
     */
    MyRectangle(float l, float w) : length(l), width(w) {}

    /**
     * @brief Sets the length of the rectangle.
     * @param l The length to set.
     */
    void setLength(float l) {
        length = l;
    }

    /**
     * @brief Sets the width of the rectangle.
     * @param w The width to set.
     */
    void setWidth(float w) {
        width = w;
    }

    /**
     * @brief Calculates and displays the area of the rectangle.
     */
    void calculateAndDisplayArea() {
        float area = length * width;
        cout << "Area of the rectangle: " << area << endl;
    }

    /**
     * @brief Calculates and displays the perimeter of the rectangle.
     */
    void calculateAndDisplayPerimeter() {
        float perimeter = 2 * (length + width);
        cout << "Perimeter of the rectangle: " << perimeter << endl;
    }

    /**
     * @brief Draws the rectangle on the canvas.
     */
    void drawOnCanvas() {
        float canvasWidth = 800; // Width of the canvas
        float canvasHeight = 600; // Height of the canvas
        float x = (canvasWidth - length) / 2;
        float y = (canvasHeight - width) / 2;
        Rectangle rect(x, y, length, width);
        rect.setFill(true);
        rect.setColor(COLOR("blue"));
        rect.penDown();
        wait(5);
    }
};

/**
 * @brief The main function of the program.
 * 
 * This function prompts the user to enter the length and width of a rectangle,
 * creates a MyRectangle object with the given dimensions, and performs various
 * calculations and operations on the rectangle. It also initializes a canvas,
 * draws the rectangle on the canvas, and waits for 5 seconds before closing the canvas.
 * 
 * @return 0 indicating successful execution of the program.
 */
int main() {
    float l, w;
    cout << "Enter length of the rectangle: ";
    cin >> l;
    cout << "Enter width of the rectangle: ";
    cin >> w;

    MyRectangle myRect(l, w);

    myRect.calculateAndDisplayArea();
    myRect.calculateAndDisplayPerimeter();

    initCanvas(); // Initialize the canvas

    myRect.drawOnCanvas(); // Draw the rectangle on the canvas

    wait(5); // Wait for 5 seconds before closing the canvas

    return 0;
}
