#include <iostream>
#include <vector>
#include <algorithm>

    // Given an array arr[], find all unique triplets in the array which add to the target.

std::vector<std::vector<int>> threeTargetSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int total = nums[i] + nums[left] + nums[right];

            if (total == target) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for second and third elements
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if (total < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 2;
    auto result = threeTargetSum(nums, target);

    for (auto triplet : result) {
        std::cout << "[ ";
        for (auto num : triplet) std::cout << num << " ";
        std::cout << "]\n";
    }
}
