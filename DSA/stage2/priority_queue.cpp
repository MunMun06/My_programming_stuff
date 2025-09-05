#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

int findKthLargest(const std::vector<int> &nums, int k) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  for (int num : nums) {
    minHeap.push(num);
    if (minHeap.size() > k) {
      minHeap.pop();
    }
  }

  return minHeap.top();
}

int connectRopes(const std::vector<int> &ropes) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(
      ropes.begin(), ropes.end());

  int totalCost = 0;

  while (minHeap.size() > 1) {
    int first = minHeap.top();
    minHeap.pop();
    int second = minHeap.top();
    minHeap.pop();

    int cost = first + second;
    totalCost += cost;

    minHeap.push(cost);
  }

  return totalCost;
}

std::vector<int> topKFrequent(const std::vector<int> &nums, int k) {
  std::unordered_map<int, int> freq;

  // Step 1: Count frequencies
  for (int num : nums) {
    freq[num]++;
  }

  // Step 2: Max-heap of (frequency, number)
  std::priority_queue<std::pair<int, int>> maxHeap;
  for (const auto &p : freq) {
    maxHeap.push({p.second, p.first}); // (freq, value)
  }

  // Step 3: Extract top K
  std::vector<int> result;
  for (int i = 0; i < k && !maxHeap.empty(); i++) {
    result.push_back(maxHeap.top().second);
    maxHeap.pop();
  }

  return result;
}

// Linked list node
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// Comparator for min-heap
struct Compare {
  bool operator()(ListNode *a, ListNode *b) {
    return a->val > b->val; // min-heap
  }
};

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
  std::priority_queue<ListNode *, std::vector<ListNode *>, Compare> minHeap;

  // Step 1: Push first node of each list
  for (auto list : lists) {
    if (list)
      minHeap.push(list);
  }

  // Dummy head to simplify linking
  // this will eventually be the output of this function
  ListNode dummy(0);
  ListNode *tail = &dummy;

  // Step 2: Extract smallest and push next
  while (!minHeap.empty()) {
    ListNode *smallest = minHeap.top();
    minHeap.pop();

    tail->next = smallest;
    tail = tail->next;

    // if there more, push the next value from the list to minHeap
    if (smallest->next) {
      minHeap.push(smallest->next);
    }
  }

  return dummy.next;
}

// Helper: print list
void printList(ListNode *head) {
  while (head) {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << "\n";
}

int main() {

  std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;

  std::cout << "The " << k
            << "th largest number is: " << findKthLargest(nums, k) << "\n";

  std::vector<int> ropes = {4, 3, 2, 6};
  std::cout << "Minimum cost to connect ropes: " << connectRopes(ropes) << "\n";

  std::vector<int> nums2 = {1, 1, 1, 2, 2, 3};
  int k2 = 2;

  std::vector<int> result = topKFrequent(nums2, k2);

  std::cout << "Top " << k2 << " frequent elements: ";
  for (int num : result) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  // Create example lists
  ListNode a1(1), a2(4), a3(5);
  a1.next = &a2;
  a2.next = &a3;

  ListNode b1(1), b2(3), b3(4);
  b1.next = &b2;
  b2.next = &b3;

  ListNode c1(2), c2(6);
  c1.next = &c2;

  std::vector<ListNode *> lists = {&a1, &b1, &c1};

  ListNode *result2 = mergeKLists(lists);
  printList(result2);

  return 0;
}

// priority queue is an abstract data type. it can be implemented with other
// data structure heap, balanced BST, unsorted array, sorted array
// needed #include <queue>

// heap is a complete binary tree that satisfies the heap property
// max-heap each node is greater than or equal to its children (default)
// min-heap each node is less than or equal to its children (with
// std::greater<T>)
// the root node is the largest (max-heap) or the smallest (min-heap)
// priority queue
// custom priority queue with custom comparator

// .push() insert an element
// .top() access the highest priority element
// .pop() remove the highest priority element

// every time the priority queue is changed. the heap automatically adjusted to
// maintained the heap property

// case where priority queue is better than sorting
// only need the top K element in priority
// need to repeatedly find/remove the top element in priority

// std::priority_queue<std::pair<int, int>>
// sort based on the .first value and .second if tied
