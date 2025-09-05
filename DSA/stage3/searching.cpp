#include <iostream>
#include <vector>

int linearSearch(const std::vector<int> &arr, int target) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == target)
      return i; // found at index i
  }
  return -1; // not found
}

int binarySearch(const std::vector<int> &arr, int target) {
  int left = 0, right = arr.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2; // avoid overflow

    if (arr[mid] == target)
      return mid; // found
    else if (arr[mid] < target)
      left = mid + 1; // target is in right half
    else
      right = mid - 1; // target is in left half
  }
  return -1; // not found
}

void printArray(std::vector<int> &arr) {
  int n = arr.size();
  std::cout << "arr = {" << arr[0];
  for (int i = 1; i < n; i++) {
    std::cout << ", " << arr[i];
  }
  std::cout << "}" << '\n';
}

int firstOccurrenceBinarySearch(const std::vector<int> &arr, int target) {
  int left = 0, right = arr.size() - 1, result = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      result = mid;    // store possible answer
      right = mid - 1; // keep searching left
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return result;
}

int lastOccurrenceBinarySearch(const std::vector<int> &arr, int target) {
  int left = 0, right = arr.size() - 1, result = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      result = mid;   // store possible answer
      left = mid + 1; // keep searching right
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return result;
}

int BinarySearchRotated(const std::vector<int> &arr, int target) {
  int left = 0, right = arr.size() - 1;

  // [7,6,1,2,3,4,5]

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
      return mid;

    // Left half is sorted
    if (arr[left] <= arr[mid]) {
      if (arr[left] <= target && target < arr[mid])
        right = mid - 1; // target in left half
      else
        left = mid + 1; // target in right half
    }
    // Right half is sorted
    else {
      if (arr[mid] < target && target <= arr[right])
        left = mid + 1; // target in right half
      else
        right = mid - 1; // target in left half
    }
  }

  return -1; // not found
}

int main() {

  std::vector<int> arr = {2, 3, 3, 6, 8, 21, 25, 25, 42, 46, 65, 72, 77, 123};
  int target = 25;

  std::cout << "binarySearch go brr\n";
  printArray(arr);
  int index = binarySearch(arr, target);
  std::cout << "target = " << target << '\n';
  std::cout << "found index = " << index << '\n';

  return 0;
}
