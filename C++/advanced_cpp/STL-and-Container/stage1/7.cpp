#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> twoSum(const std::vector<int>& nums, int start, int target) {
    std::vector<std::vector<int>> res;
    int left = start, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            res.push_back({nums[left], nums[right]});
            while (left < right && nums[left] == nums[left + 1]) left++;
            while (left < right && nums[right] == nums[right - 1]) right--;
            left++;
            right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return res;
}

std::vector<std::vector<int>> kSum(const std::vector<int>& nums, int start, int k, int target) {
    std::vector<std::vector<int>> res;

    if (start >= nums.size()) return res;

    // Base case: reduce to 2Sum
    if (k == 2) return twoSum(nums, start, target);

    for (int i = start; i < nums.size(); ++i) {
        // Skip duplicates
        if (i > start && nums[i] == nums[i - 1]) continue;

        auto subRes = kSum(nums, i + 1, k - 1, target - nums[i]);
        for (auto& subset : subRes) {
            subset.insert(subset.begin(), nums[i]);
            res.push_back(subset);
        }
    }
    return res;
}

int main() {
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int k = 4;
    int target = 0;

    std::sort(nums.begin(), nums.end()); // Always sort before applying two pointers

    auto result = kSum(nums, 0, k, target);

    for (auto group : result) {
        std::cout << "[ ";
        for (int num : group) std::cout << num << " ";
        std::cout << "]\n";
    }

    return 0;
}
