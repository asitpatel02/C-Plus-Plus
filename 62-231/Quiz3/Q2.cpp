#include <simplecpp>
#include <algorithm> // Include the algorithm header for sorting

using namespace simplecpp;

bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false; // Empty matrix

    int rows = matrix.size();
    int cols = matrix[0].size();

    // Start from the top-right corner
    int row = 0;
    int col = cols - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target)
            return true; // Found the target
        else if (matrix[row][col] > target)
            col--; // Move left in the current row
        else
            row++; // Move down to the next row
    }
    return false; // Target not found
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {9, 10, 11, 12}
    };

    int target = 6;
    if (searchMatrix(matrix, target))
        cout << "Target " << target << " is found in the matrix." << endl;
    else
        cout << "Target " << target << " is not found in the matrix." << endl;

    // Flatten the matrix into a single vector
    vector<int> flattened;
    for (const auto& row : matrix) {
        flattened.insert(flattened.end(), row.begin(), row.end());
    }

    // Sort the flattened vector in ascending order
    sort(flattened.begin(), flattened.end());

    // Reshape the sorted vector back into a matrix
    vector<vector<int>> sortedMatrix;
    for (unsigned int i = 0; i < matrix.size(); ++i) {
        vector<int> newRow(matrix[i].size());
        for (unsigned int j = 0; j < matrix[i].size(); ++j) {
            newRow[j] = flattened[i * matrix[i].size() + j];
        }
        sortedMatrix.push_back(newRow);
    }

    // Print the sorted matrix
    cout << "Sorted matrix:" << endl;
    for (const auto& row : sortedMatrix) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
