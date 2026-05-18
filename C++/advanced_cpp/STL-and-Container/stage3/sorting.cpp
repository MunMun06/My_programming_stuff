#include <algorithm>
#include <iostream>
#include <vector>

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    // the largest value is "bubble" to the top and then the next largest

    // Last i elements are already in place
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap arr[j] and arr[j+1]
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        swapped = true;
      }
    }

    // If no swaps happened, the array is already sorted
    if (!swapped)
      break;
  }
}

void insertionSort(std::vector<int> &arr) {
  for (size_t i = 1; i < arr.size(); i++) {
    int key = arr[i]; // the element we want to insert into the sorted part
    int j = i - 1;
    // create and expand the sorted part by inserting elements

    // Move elements that are greater than key to one position ahead
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    // place key in its correct position
    arr[j + 1] = key;
  }
}

void selectionSort(std::vector<int> &arr) {
  int n = arr.size();

  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;

    // find the index of the next smallest element
    // Find the index of the smallest element in the unsorted part
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    // swap the next smallest element with the first element of the unsorted
    // part Swap smallest element with the first element of the unsorted part
    if (minIndex != i) {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

void merge(std::vector<int> &arr, int left, int mid, int right) {
  int n1 = mid - left + 1; // size of left subarray
  int n2 = right - mid;    // size of right subarray

  // sort then merge the subarray
  // the array was never spilt
  // only the index changes to mimic spilting

  std::vector<int> L(n1), R(n2); // temp vector

  // copy data to temp vector
  for (int i = 0; i < n1; ++i)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; ++j)
    R[j] = arr[mid + 1 + j];

  // merge the temp vector back into arr[left..right]
  int i = 0, j = 0, k = left; // index for L,R and main array respectively
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  // copy remaining elements of vector L and R, if any
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void mergeSort(std::vector<int> &arr, int left, int right) {

  // this function is the main part of the mergesort
  // spilt the array in 2,call mergesort on the left and right part and call
  // merge
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // choose last element as pivot
  int i = low - 1;       // index of element smaller than pivot

  // the array also never split like mergeSort
  // only the index change to mimic spilting

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1; // pivot index
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high); // pi is pivot index

    quickSort(arr, low, pi - 1);  // left side
    quickSort(arr, pi + 1, high); // right side
  }
}

void heapify(std::vector<int> &arr, int n, int i) {
  int largest = i;       // Assume current node is largest (index)
  int left = 2 * i + 1;  // Left child index
  int right = 2 * i + 2; // Right child index

  // If left child is larger than root
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // If right child is larger than current largest
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If largest is not the root
  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    heapify(arr, n, largest); // Recursively heapify the affected subtree
  }
}

void heapSort(std::vector<int> &arr) {
  int n = arr.size();

  // Build max heap (bottom-up)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Extract elements from heap one by one
  for (int i = n - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]); // Move current root to end
    heapify(arr, i, 0);        // Heapify reduced heap
  }
}

void countingSort(std::vector<int> &arr) {
  if (arr.empty())
    return;

  // 1. Find min and max
  int minVal = arr[0], maxVal = arr[0];
  for (int num : arr) {
    if (num < minVal)
      minVal = num;
    if (num > maxVal)
      maxVal = num;
  }

  int range = maxVal - minVal + 1;

  // 2. Count occurrences
  // num is the value not the index
  std::vector<int> count(range, 0);
  for (int num : arr) {
    count[num - minVal]++;
  }

  // 3. Prefix sum to get positions
  // after this step count[x] is the amount of number <= x + minVal
  for (size_t i = 1; i < count.size(); i++) {
    count[i] += count[i - 1];
  }

  // 4. Build output array (iterate backwards for stability)
  std::vector<int> output(arr.size());
  for (int i = arr.size() - 1; i >= 0; i--) {
    output[--count[arr[i] - minVal]] = arr[i];
  }

  // 5. Copy back
  arr = output;
}

// Counting sort helper, but only on a specific digit
void countingSortByDigit(std::vector<int> &arr, int exp) {
  int n = arr.size();
  std::vector<int> output(n);
  std::vector<int> count(10, 0); // digits 0-9

  // Count occurrences of digits at this place
  for (int num : arr) {
    int digit = (num / exp) % 10;
    count[digit]++;
  }

  // Prefix sums
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Build output (stable: iterate backwards)
  for (int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    output[--count[digit]] = arr[i];
  }

  // Copy back
  arr = output;
}

void radixSort(std::vector<int> &arr) {
  // Find the max value to know how many digits to process
  int maxVal = *std::max_element(arr.begin(), arr.end());

  // base 10 positive integer

  // Do counting sort for each digit (units, tens, hundreds…)
  for (int exp = 1; maxVal / exp > 0; exp *= 10) {
    countingSortByDigit(arr, exp);
  }
}

void bucketSort(std::vector<float> &arr) {
  int n = arr.size();
  if (n <= 0)
    return;

  // 1. Create empty buckets
  std::vector<std::vector<float>> buckets(n);

  // 2. Scatter: put array elements in different buckets
  for (float num : arr) {
    int index = n * num; // since arr[i] is assumed to be in [0, 1)
    buckets[index].push_back(num);
  }

  // 3. Sort individual buckets
  for (auto &bucket : buckets) {
    std::sort(bucket.begin(), bucket.end()); // could use insertion sort
  }

  // 4. Concatenate buckets back into arr
  int idx = 0;
  for (const auto &bucket : buckets) {
    for (float num : bucket) {
      arr[idx++] = num;
    }
  }
}

int main() {
  int arr[] = {5, 1, 4, 2, 8, 14, 15, 6, 3, 3, 4, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, n);

  std::cout << "Here are the O(n^2) sorting algorithm\n \n";

  std::cout << "bubbleSort output: ";
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";

  std::vector<int> arr2 = {5, 1, 4, 2, 8, 14, 15, 6, 3};

  insertionSort(arr2);

  std::cout << "insertionSort output: ";

  for (size_t i = 0; i < arr2.size(); i++) {
    std::cout << arr2[i] << " ";
  }
  std::cout << "\n";

  std::vector<int> arr3 = {5, 1, 4, 2, 8, 14, 15, 6, 3};

  selectionSort(arr3);

  std::cout << "selectionSort output: ";

  std::cout << "Sorted array: ";
  for (int num : arr3) {
    std::cout << num << " ";
  }
  std::cout << "\n \n";

  std::cout << "Here are the divide et impera sorting algorithm\n \n";
  std::vector<int> arr4 = {5, 1, 4, 2, 8, 14, 15, 6, 3};
  mergeSort(arr4, 0, arr4.size() - 1);

  std::cout << "mergeSort output: ";

  for (int num : arr4) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  int arr5[] = {13, 26, 49, 96, 14, 36, 88, 63, 44, 56, 82};
  int n2 = sizeof(arr5) / sizeof(arr5[0]);

  quickSort(arr5, 0, n2 - 1);

  std::cout << "quickSort output (The one i actually wanted): ";

  for (int i = 0; i < n2; i++)
    std::cout << arr5[i] << " ";
  std::cout << "\n";

  std::vector<int> arr6 = {5, 1, 4, 2, 8, 14, 15, 6, 3};

  heapSort(arr6);

  std::cout << "heapSort output: ";

  for (int num : arr6)
    std::cout << num << " ";
  std::cout << "\n\n";

  std::vector<int> arr7 = {5, 2, 9, 5, 2, 3, 5};
  countingSort(arr7);

  std::cout << "Here are the linear time algorithm\n\n";

  std::cout << "countingSort output: ";
  for (int num : arr7) {
    std::cout << num << " ";
  }

  std::cout << '\n';

  std::vector<int> arr8 = {5,   45, 9,  5,  64, 3, 5, 126, 843,
                           632, 12, 75, 35, 3,  7, 6, 3};
  countingSort(arr8);

  std::cout << "radixSort output: ";
  for (int num : arr8) {
    std::cout << num << " ";
  }

  std::cout << '\n';

  std::vector<float> arr9 = {0.78, 0.17, 0.39, 0.26, 0.72,
                             0.94, 0.21, 0.12, 0.23, 0.68};
  bucketSort(arr9);

  std::cout << "bucketSort output: ";
  for (float num : arr9) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  return 0;
}
