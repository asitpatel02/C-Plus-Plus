#include <simplecpp>

using namespace simplecpp;

int findSmallestPositive(vector<int>& nums) {
    int n = nums.size();

    // Rearrange the array such that each positive number x is placed at index x - 1
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Iterate through the array to find the smallest positive integer that does not appear
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1; // Found the smallest positive integer that does not appear
        }
    }

    return n + 1; // If all positive integers from 1 to n appear, return n + 1
}

int main() {
    vector<int> nums = {3, 4, -1, 1};
    int smallestPositive = findSmallestPositive(nums);
    cout << "The smallest positive integer that does not appear in the array is: " << smallestPositive << endl;
    return 0;
}
