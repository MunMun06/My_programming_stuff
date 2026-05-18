#include <algorithm>
#include <iostream>
#include <vector>

void removeDuplicates(std::vector<int> &nums) {
  // std::unique return an iterator after removing duplicates
  // it move duplicates to the back
  auto newEnd = std::unique(nums.begin(), nums.end());
  nums.erase(newEnd, nums.end()); // erase duplicates from vector
}

void rotateArray(std::vector<int> &nums, int k) {

  // 1 2 3 4 5 6 7  k = 3 to
  // 5 6 7 1 2 3 4

  int n = nums.size();
  k = k % n; // handle k > n

  // Reverse entire array
  std::reverse(nums.begin(), nums.end());

  // Reverse first k elements
  std::reverse(nums.begin(), nums.begin() + k);

  // Reverse remaining elements
  std::reverse(nums.begin() + k, nums.end());
}

std::vector<std::pair<int, int>>
mergeIntervals(std::vector<std::pair<int, int>> &intervals) {
  if (intervals.empty())
    return {};

  // 1. Sort by start time
  std::sort(intervals.begin(), intervals.end());

  // 2. Result container
  std::vector<std::pair<int, int>> merged;
  merged.push_back(intervals[0]);

  // 3. Merge process
  for (size_t i = 1; i < intervals.size(); i++) {
    auto &last = merged.back(); // last merged interval

    if (intervals[i].first <= last.second) {
      // Overlap: extend the last merged interval's end
      last.second = std::max(last.second, intervals[i].second);
    } else {
      // No overlap: push new interval
      merged.push_back(intervals[i]);
    }
  }

  return merged;
}

std::vector<int> spiralOrder(const std::vector<std::vector<int>> &matrix) {
  std::vector<int> result;
  if (matrix.empty())
    return result;

  int top = 0;
  int bottom = matrix.size() - 1;
  int left = 0;
  int right = matrix[0].size() - 1;

  while (top <= bottom && left <= right) {
    // 1. Left → Right
    for (int col = left; col <= right; col++) {
      result.push_back(matrix[top][col]);
    }
    top++;

    // 2. Top → Bottom
    for (int row = top; row <= bottom; row++) {
      result.push_back(matrix[row][right]);
    }
    right--;

    // 3. Right → Left
    if (top <= bottom) {
      for (int col = right; col >= left; col--) {
        result.push_back(matrix[bottom][col]);
      }
      bottom--;
    }

    // 4. Bottom → Top
    if (left <= right) {
      for (int row = bottom; row >= top; row--) {
        result.push_back(matrix[row][left]);
      }
      left++;
    }
  }

  return result;
}

void rotateMatrix(std::vector<std::vector<int>> &matrix) {
  int n = matrix.size();

  // Step 1: Transpose
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      std::swap(matrix[i][j], matrix[j][i]);
    }
  }

  // Step 2: Reverse each row
  for (int i = 0; i < n; i++) {
    std::reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main() {

  std::vector<int> v = {10, 20, 30};

  // Normal iterator
  for (auto it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";

  std::cout << "\n";

  // Reverse iterator
  for (auto it = v.rbegin(); it != v.rend(); ++it)
    std::cout << *it << " ";

  std::cout << "\n";

  std::vector<std::pair<int, int>> intervals = {
      {1, 3}, {2, 6}, {8, 10}, {15, 18}};

  auto result = mergeIntervals(intervals);

  for (auto &p : result) {
    std::cout << "[" << p.first << ", " << p.second << "] ";
  }
  std::cout << "\n";

  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  std::vector<int> order = spiralOrder(matrix);

  for (int num : order) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  std::vector<std::vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  rotateMatrix(matrix2);

  for (const auto &row : matrix2) {
    for (int num : row) {
      std::cout << num << " ";
    }
    std::cout << "\n";
  }

  return 0;
}

// vector is a dynamic array in heap memory
// grow and shrink automatically
// store element continuously and support random access (v[i] is O(1))

// size is the amount of element in the vector
// size constantly change
// capacity is the max amount of element in the vector
// capacity automatically change when size > capacity
// and can be manually change

// container
// push_back() add to the end
// random access: operator[] .at()
// capacity management: .size() .capacity() .reserve()
// element management: .insert() .erase() .clear()

// iterator
// begin() first element, end() one past last element
// rbegin() rend(). reverse iterator
// cbegin() cend(). constant iterator

// algorithm. STL algorithms work with iterator
// so std::vector can use almost all algorithms in <algorithm>
// sort(v.begin(), v.end())
// find(v.begin(), v.end(), value)
// reverse(v.begin(), v.end())
// count(v.begin(), v.end(), value)
// binary_search(v.begin(), v.end(), value)

// iterator invalidation
// happen when using an old iterator after the vector is changed
// copy to new location or erasing/inserting an element
// solution. always get new iterator or use indices instead of iterator
