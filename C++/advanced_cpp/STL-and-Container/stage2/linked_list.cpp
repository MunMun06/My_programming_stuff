#include <iostream>

// node** is C style
// node*& is C++ style and cleaner syntax

struct Node {
  int data;
  Node *next;

  Node(int val) : data(val), next(nullptr) {}
};

/*
class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};
*/

void insertAtHead(Node *&head, int val) {
  Node *newHead = new Node(val); // create a node with value = val.
  newHead->next = head;
  head = newHead;
}

void printList(Node *head) {
  Node *curr = head; // node pointer curr is pointed to head
  while (curr) {
    std::cout << curr->data << " -> ";
    curr = curr->next;
  }
  std::cout << "NULL\n";
}

void deleteNodeWithVal(Node *&head, int val) {

  // delete the first node with value = val

  if (head == nullptr)
    return;

  // If head is the node to delete
  if (head->data == val) {
    Node *temp = head;
    head = head->next;
    delete temp;
    return;
  }

  // Find the previous node
  Node *curr = head;
  while (curr->next && curr->next->data != val) {
    curr = curr->next;
  }

  // If found

  // true if curr->next is not nullptr
  if (curr->next) {
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
  }
};

void DeleteNthNode(Node *&head, int nth) {

  // nth is 0-based

  // check for empty list
  if (!head)
    return;

  // if head need to be delete
  if (nth == 0) {
    Node *temp = head;
    head = head->next;
    delete temp;
    return;
  }

  Node *curr = head;

  // move curr to the nth - 1 node
  // prevent doing curr = curr->next when curr->next is nullptr
  for (int i = 0; i < nth - 1 && curr->next; i++) {
    curr = curr->next;
  }

  // delete nth and correctly change the next pointer
  // Make sure nth node exists
  if (!curr->next)
    return;

  Node *temp = curr->next;
  curr->next = curr->next->next;
  delete temp;
};

void reverseList(Node *&head) {
  Node *prev = nullptr;
  Node *curr = head;

  while (curr != nullptr) {
    Node *next = curr->next; // Save next node
    curr->next = prev;       // Reverse the pointer
    prev = curr;             // Move prev to current
    curr = next;             // Move to next node
  }

  head = prev; // New head of the reversed list
};

Node *reverseListRecursive(Node *node) {
  // Base case: empty or one-node list
  if (node == nullptr || node->next == nullptr) {
    return node;
  }

  // Recursive case: reverse the rest of the list
  Node *newHead = reverseListRecursive(node->next);

  // Flip the direction
  node->next->next = node;
  node->next = nullptr;

  return newHead;
}

Node *reverseBetween(Node *head, int m, int n) {
  if (!head || m == n)
    return head;

  // 1-based indices
  // Dummy node to handle edge cases like m == 1
  Node dummy(0);       // stack-allocated object instead of heap-allocated
  dummy.next = head;   // no need to delete. memory is automatically managed
  Node *prev = &dummy; // we only need dummy temporarily so this is perfect

  // 1. Move prev to one node before m
  for (int i = 1; i < m; ++i) {
    prev = prev->next;
  }

  // Now prev -> node before m
  // curr -> m-th node (start of the section to reverse)
  Node *curr = prev->next;
  Node *then = curr->next;

  // 2. Reverse nodes between m and n
  for (int i = 0; i < n - m; ++i) {
    curr->next = then->next;
    then->next = prev->next;
    prev->next = then;
    then = curr->next;
  }

  return dummy.next;
}

bool hasCycle(Node *head) {
  Node *slow = head;
  Node *fast = head;

  while (fast && fast->next) {
    slow = slow->next;       // move 1 step
    fast = fast->next->next; // move 2 steps

    if (slow == fast)
      return true; // cycle detected
  }

  return false; // no cycle
}

Node *detectCycleStart(Node *head) {
  Node *slow = head;
  Node *fast = head;

  // Step 1: Detect if a cycle exists with fast and slow
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      // Step 2: Move one pointer to head
      // then move both pointers 1 nodes at a time.
      // they will meet at the start of the cycle
      slow = head;
      while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
      }
      return slow; // This is the start of the cycle
    }
  }

  return nullptr; // No cycle
};

void removeCycle(Node *head) {
  Node *slow = head;
  Node *fast = head;

  // Step 1: Detect a cycle
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      // Step 2: Find the start of the cycle
      slow = head;
      while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
      }
      // Step 3: Break the cycle
      fast->next = nullptr;
      return;
    }
  }
};

int main() {
  Node *head = nullptr;

  insertAtHead(head, 10);
  insertAtHead(head, 20);
  insertAtHead(head, 30);
  printList(head); // should print: 30 -> 20 -> 10 -> NULL

  reverseList(head);
  printList(head);

  head = reverseListRecursive(head);
  printList(head);

  head = reverseBetween(head, 2, 3);
  printList(head);
  return 0;
}
