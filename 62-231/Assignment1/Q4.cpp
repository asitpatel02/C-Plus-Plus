/*
4. Pattern of Circles
• Generate a program that draws a pattern consisting of multiple circles. Each row should contain one more circle than the row above it, forming a pyramid-like structure.
• Utilize nested for loops: the outer loop for the rows and the inner loop for the circles in each row.
• The circles in each row should be evenly spaced and aligned centrally with the pattern.
*/
#include <simplecpp>

int main() {
    // Set up graphics window
    initCanvas("Pattern of Circles", 800, 600);

    // Ask the user for the number of rows
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    // Radius of circles
    const int circleRadius = 15;
    // Horizontal spacing between circles
    const int horizontalSpacing = 2 * circleRadius;

    // Pre-calculate the positions of circles for all rows
    vector<vector<pair<int, int>>> circlePositions(numRows);
    for (int i = 0; i < numRows; ++i) {
        int numCircles = i + 1;
        int startX = (800 - numCircles * horizontalSpacing) / 2;
        for (int j = 0; j < numCircles; ++j) {
            int x = startX + j * horizontalSpacing;
            int y = 100 + i * 2 * circleRadius;
            circlePositions[i].push_back(make_pair(x, y));
        }
    }

    // Draw all circles
    beginFrame();
    for (int i = 0; i < numRows; ++i) {
        for (const auto& pos : circlePositions[i]) {
            Circle circle(pos.first, pos.second, circleRadius);
            circle.setFill(true);
            circle.imprint();
        }
    }
    endFrame();

    // Wait for user to close the graphics window
    getClick();

    // Close graphics window
    closeCanvas();
    return 0;
}
