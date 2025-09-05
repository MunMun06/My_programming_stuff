#include <iostream>

    // given a sorted array. find the 0-based indices of the two numbers that add up to the target.
    // start with left and right pointer. if the sum is > target move *right to left and vice versa. 

int main() {
    int arr[] = {1, 2, 3, 4, 6};
    int target = 6;
    int n = sizeof(arr) / sizeof(arr[0]);

    int left = 0, right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            std::cout << "Pair found at indices: " << left << " and " << right << '\n';
            return 0;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    std::cout << "No pair found\n";
    return 0;
}
