#include <simplecpp>
#include <vector>

int findPivotIndex(const vector<int>& vec) {
    int totalSum = 0;
    int leftSum = 0;

    // Calculate the total sum of the array
    for (int num : vec) {
        totalSum += num;
    }

    // Iterate through the array and check for pivot index
    for (int i = 0; i < vec.size(); i++) {
        // Check if the sum of numbers to the left is equal to the sum of numbers to the right
        if (leftSum == totalSum - leftSum - vec[i]) {
            return i;
        }

        // Update the left sum
        leftSum += vec[i];
    }

    // If no pivot index is found, return -1
    return -1;
}

int main() {
    // Test the findPivotIndex function
    vector<int> vec = {1, 7, 3, 6, 5, 6};
    int pivotIndex = findPivotIndex(vec);

    if (pivotIndex != -1) {
        cout << "Pivot index found at position: " << pivotIndex << endl;
    } else {
        cout << "No pivot index found." << endl;
    }

    return 0;
}
