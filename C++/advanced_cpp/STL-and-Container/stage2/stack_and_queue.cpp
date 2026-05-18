#include <iostream>
#include <queue>
#include <stack>
#include <string>

std::string reverseString(const std::string &str) {
  std::stack<char> stack;

  // stack
  // top() see the top value
  // push(x) add x to the top of the stack
  // pop() remove the top value
  // empty() check if empty

  // Push each character into the stack
  for (char c : str) {
    stack.push(c);
  }

  // Pop each character from the stack to reverse the string
  std::string reversed;
  while (!stack.empty()) {
    reversed.push_back(stack.top());
    stack.pop();
  }

  return reversed;
};

void taskScheduler() {
  std::queue<std::string> tasks;

  // queue
  // front() see the value infront
  // push(x) add x to the back of the queue
  // pop() remove the value infront
  // empty() check if empty

  // Enqueue some tasks
  tasks.push("Task 1");
  tasks.push("Task 2");
  tasks.push("Task 3");

  // Process tasks in FIFO order
  while (!tasks.empty()) {
    std::cout << "Executing: " << tasks.front() << std::endl;
    tasks.pop();
  }
};

void nextGreaterElement(int arr[], int result[], int n) {
  std::stack<int> st; // This holds the actual values

  // top = smallest

  for (int i = n - 1; i >= 0; --i) {
    // Remove elements smaller than or equal to arr[i]
    // pop if top <= arr[i]
    while (!st.empty() && st.top() <= arr[i]) {
      st.pop();
    }

    // Set result[i]
    if (st.empty()) {
      result[i] = -1;
    } else {
      result[i] = st.top();
    }

    // Push current element to stack for future comparisons
    st.push(arr[i]);
  }
}

void nextGreaterCircular(int arr[], int result[], int n) {
  std::stack<int> st;

  for (int i = 2 * n - 1; i >= 0; --i) {
    int actualIndex = i % n;

    // Pop values that are less than or equal to arr[actualIndex]
    while (!st.empty() && st.top() <= arr[actualIndex]) {
      st.pop();
    }

    // Fill result array only during the first pass (i < n)
    if (i < n) {
      result[actualIndex] = st.empty() ? -1 : st.top();
    }

    // Push current value into the stack
    st.push(arr[actualIndex]);
  }
}

int largestRectangleArea(int heights[], int n) {

  // Given an array of bar heights representing a histogram,
  // find the area of the largest rectangle that can be formed within the bounds
  // of the histogram.

  std::stack<int> st;
  int maxArea = 0;

  for (int i = 0; i <= n; ++i) {
    int currHeight = (i == n) ? 0 : heights[i];

    // maintain the stack of indices where heights are increasing.

    while (!st.empty() && currHeight < heights[st.top()]) {
      int height = heights[st.top()];
      st.pop();

      int width;
      if (st.empty()) {
        width = i;
      } else {
        width = i - st.top() - 1;
      }

      int area = height * width;
      maxArea = std::max(maxArea, area);
    }

    st.push(i);
  }

  return maxArea;
}

int trap(int height[], int n) {
  int left = 0, right = n - 1;
  int leftMax = 0, rightMax = 0;
  int water = 0;

  // using two pointers

  while (left < right) {
    if (height[left] < height[right]) {
      if (height[left] >= leftMax)
        leftMax = height[left];
      else
        water += leftMax - height[left];
      left++;
    } else {
      if (height[right] >= rightMax)
        rightMax = height[right];
      else
        water += rightMax - height[right];
      right--;
    }
  }

  return water;
}

int trapWithStack(int height[], int n) {
  std::stack<int> st;
  int water = 0;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && height[i] > height[st.top()]) {
      int top = st.top();
      st.pop();

      if (st.empty())
        break;

      int distance = i - st.top() - 1;
      int boundedHeight = std::min(height[i], height[st.top()]) - height[top];
      water += distance * boundedHeight;
    }
    st.push(i);
  }

  return water;
}

// 0,1,0,2,1,0,1,3,2,1,2,1
// 1 0 1 0 1 2 1 0 0 1 0 1 = 8
// 0 0 1 0 1 2 1 0 0 1 0 0 = 6
// which means no wall

int main() {
  int arr[] = {4, 5, 2, 10};
  const int n = sizeof(arr) / sizeof(arr[0]);
  int result[n];

  nextGreaterElement(arr, result, n);

  std::cout << "Next Greater Elements: ";
  for (int i = 0; i < n; ++i) {
    std::cout << result[i] << " ";
  }
  std::cout << "\n";
}
