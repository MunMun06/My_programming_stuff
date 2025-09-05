#include <iostream>
#include <vector>

int sumArray(int arr[], int n) {
  if (n == 0)
    return 0;                               // base case
  return arr[n - 1] + sumArray(arr, n - 1); // recursive step
}

void reverseArray(int arr[], int start, int end) {
  if (start >= end)
    return; // base case
  std::swap(arr[start], arr[end]);
  reverseArray(arr, start + 1, end - 1); // recursive step
}

int power(int x, int n) {
  if (n == 0)
    return 1;                 // base case
  return x * power(x, n - 1); // recursive step
}

int sumDigits(int n) {
  if (n == 0)
    return 0; // base case
  return n % 10 + sumDigits(n / 10);
}

int factorial(int x) {
  if (x <= 1)
    return 1;
  return x * factorial(x - 1);
}

int fibonacci(int n) {
  if (n == 0)
    return 0; // base case
  if (n == 1)
    return 1; // base case
  return fibonacci(n - 1) + fibonacci(n - 2);
}

void towerOfHanoi(int n, char from, char to, char aux) {
  if (n == 1) {
    std::cout << "Move disk 1 from " << from << " to " << to << '\n';
    return;
  }
  towerOfHanoi(n - 1, from, aux, to); // move n-1 disks to auxiliary
  std::cout << "Move disk " << n << " from " << from << " to " << to << '\n';
  towerOfHanoi(n - 1, aux, to, from); // move n-1 disks to destination
}

void generateSubsets(std::vector<int> &nums, int index,
                     std::vector<int> &current) {
  if (index == nums.size()) {
    // print the current subset
    // current also work as output
    std::cout << "{ ";
    for (int x : current)
      std::cout << x << " ";
    std::cout << "}\n";
    return;
  }

  // Exclude nums[index]
  generateSubsets(nums, index + 1, current);

  // Include nums[index]
  current.push_back(nums[index]);
  generateSubsets(nums, index + 1, current);

  // Backtrack (undo the choice)
  current.pop_back();
}
void generatePermutations(std::vector<int> &nums, int start) {
  if (start == nums.size()) {
    for (int x : nums)
      std::cout << x << " ";
    std::cout << "\n";
    return;
  }

  for (int i = start; i < nums.size(); i++) {
    std::swap(nums[start], nums[i]);       // choose
    generatePermutations(nums, start + 1); // explore
    std::swap(nums[start], nums[i]);       // backtrack
  }
}
void generateCombinations(std::vector<int> &nums, int k, int start,
                          std::vector<int> &current) {
  if (current.size() == k) {
    for (int x : current)
      std::cout << x << " ";
    std::cout << "\n";
    return;
  }

  for (int i = start; i < nums.size(); i++) {
    current.push_back(nums[i]);                    // choose
    generateCombinations(nums, k, i + 1, current); // explore
    current.pop_back();                            // backtrack
  }
}
int main() {

  int n = 3;                      // number of disks
  towerOfHanoi(n, 'A', 'C', 'B'); // A=source, C=destination, B=auxiliary

  std::vector<int> nums = {1, 2, 3};
  std::vector<int> current;
  generateSubsets(nums, 0, current);

  std::vector<int> nums2 = {1, 2, 3};
  generatePermutations(nums2, 0);

  std::vector<int> nums3 = {1, 2, 3, 4};
  std::vector<int> current2;
  int k = 2;
  generateCombinations(nums3, k, 0, current);

  return 0;
}
