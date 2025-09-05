#include <iostream>
#include <queue>
#include <stack>

// Binary tree
// each node has at most 2 children
// the children are commonly called left and right
// somewhat similar to linked list

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode *root) {

  // L -> Root -> R
  if (!root)
    return; // if nullptr, end
  inorder(root->left);
  std::cout << root->val << " "; // print current node value
  inorder(root->right);
}

void inorderIterative(TreeNode *root) {
  std::stack<TreeNode *> st;
  TreeNode *curr = root;

  while (curr || !st.empty()) {
    while (curr) {
      st.push(curr);
      curr = curr->left; // process left
    }

    curr = st.top();
    st.pop();
    std::cout << curr->val << " "; // print current node value
    curr = curr->right;            // process right
  }
}

void preorder(TreeNode *root) {
  if (!root)
    return;
  std::cout << root->val; // Visit current node
  preorder(root->left);   // Left subtree
  preorder(root->right);  // Right subtree
}

void preorderIterative(TreeNode *root) {
  if (!root)
    return;
  std::stack<TreeNode *> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode *curr = st.top();
    st.pop();
    std::cout << curr->val;

    if (curr->right)
      st.push(curr->right); // Push right first
    if (curr->left)
      st.push(curr->left); // So left is processed first
  }
}

void postorder(TreeNode *root) {
  if (!root)
    return;
  postorder(root->left);  // left
  postorder(root->right); // right
  std::cout << root->val; // root
}

void postorderIterative(TreeNode *root) {
  if (!root)
    return;
  std::stack<TreeNode *> st1, st2;
  st1.push(root);

  while (!st1.empty()) {
    TreeNode *curr = st1.top();
    st1.pop();
    st2.push(curr);

    if (curr->left)
      st1.push(curr->left);
    if (curr->right)
      st1.push(curr->right);
  }

  while (!st2.empty()) {
    std::cout << st2.top()->val;
    st2.pop();
  }
}

void levelOrderTraversal(TreeNode *root) {
  if (!root)
    return;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *current = q.front();
    q.pop(); // pop

    std::cout << current->val << " "; // print the value of current node

    if (current->left)
      q.push(current->left); // curr move to left and push left if it exist
    if (current->right)
      q.push(current->right); // curr move to left and push left if it exist
  }
}

int treeHeight(TreeNode *root) {
  if (!root)
    return -1; // or return 0 if you define height of empty tree as 0
               // -1 mean height = edges count. 0 mean height = nodes count

  int leftHeight = treeHeight(root->left);
  int rightHeight = treeHeight(root->right);

  return 1 + std::max(leftHeight, rightHeight); // +1 in all case
}

int checkHeight(TreeNode *root) {
  if (!root)
    return 0;

  int left = checkHeight(root->left);
  if (left == -1)
    return -1;

  int right = checkHeight(root->right);
  if (right == -1)
    return -1;

  if (abs(left - right) > 1)
    return -1;

  return std::max(left, right) + 1;
  // return the height of the tree if its balanced
}

bool isBalanced(TreeNode *root) {
  return checkHeight(root) != -1;
  // a binary tree is balanced if for every node,
  // the height difference between it left and right subtrees is at most 1
}

int diameterOfBinaryTreeHelper(TreeNode *root, int &diameter) {
  if (!root)
    return 0;

  int leftHeight = diameterOfBinaryTreeHelper(root->left, diameter);
  int rightHeight = diameterOfBinaryTreeHelper(root->right, diameter);

  // Update max diameter
  diameter = std::max(diameter, leftHeight + rightHeight);

  // Return height of subtree
  return std::max(leftHeight, rightHeight) + 1;
  // at any node. the length of the lognest path is
  // height(left subtree) + height(right subtree)
}

int diameterOfBinaryTree(TreeNode *root) {
  int diameter = 0;
  diameterOfBinaryTreeHelper(root, diameter);
  return diameter;
  // diameter or width is the length of the longest path between any 2 nodes
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (!root || root == p || root == q)
    return root;

  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);

  if (left && right)
    return root;              // Found both sides
  return left ? left : right; // One side is non-null
  // the LCA of two nodes p and q is the lowest node in the tree
  // that has both p and q as descendants
}

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (!p && !q)
    return true;
  if (!p || !q)
    return false;
  if (p->val != q->val)
    return false;

  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  // 2 binary trees are the same if they have the same structure and each node
  // has the same value.
}

bool isMirror(TreeNode *t1, TreeNode *t2) {
  if (!t1 && !t2)
    return true;
  if (!t1 || !t2)
    return false;
  if (t1->val != t2->val)
    return false;

  return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
  // isMirror is very similar to isSameTree
}

bool isSymmetric(TreeNode *root) {
  if (!root)
    return true;
  return isMirror(root->left, root->right);
}

int main() { return 0; }
