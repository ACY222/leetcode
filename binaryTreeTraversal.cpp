#include <iostream>
#include <stack>
#include <vector>
using std::vector, std::stack, std::cout, std::endl;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node() : val(0), left(nullptr), right(nullptr) {}
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

// root -> left -> right
vector<int> preorderTraversal(Node *root) {
  if (!root) {
    return {};
  }
  vector<int> result;
  stack<Node*> st;
  st.push(root);
  while (!st.empty()) {
    Node *node { st.top() };
    st.pop();
    result.push_back(node->val);
    if (node->right) {st.push(node->right); }
    if (node->left) { st.push(node->left); }
  }
  return result;
}

// left -> root ->right
vector<int> inorderTraversal(Node *root) {
  if (!root) {
    return {};
  }
  vector<int> result;
  stack<Node*> st;
  Node *curr { root };
  while (curr || !st.empty()) {
    // keep pushing left subtrees
    while (curr) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    // Now curr is a leaf, or a parent with only right child
    // But no matter what it is, curr's val comes first
    st.pop();
    result.push_back(curr->val);
    // if curr is a left, then next loop we will cope with its parent tree
    // if not, we will cope with its right subtree
    curr = curr->right;
  }
  return result;
}

// left -> right -> root
vector<int> postorderTraversal(Node *root) {
  if (!root) {
    return {};
  }
  vector<int> result;
  stack<Node*> st;
  Node *prev { nullptr }, *curr { nullptr };
  st.push(root);
  while (!st.empty()) {
    curr = st.top();
    // if curr is a leaf, or prev is its child
    if ((!curr->left && !curr->right) || (prev && (prev == curr->left || prev == curr->right))) {
      result.push_back(curr->val);
      st.pop();
      prev = curr;
    }
    else {
      if (curr->right) {st.push(curr->right); }
      if (curr->left) { st.push(curr->left); }
    }
  }
  return result;
}

void printResult(int mode, vector<int> result) {
  cout << "The result of ";
  switch (mode) {
    case 1:
      cout << "preorderTraversal is:\n  ";
      break;
    case 2:
      cout << "inorderTraversal is:\n  ";
      break;
    case 3:
      cout << "postorderTraversal is:\n  ";
      break;
    default:
      break;
  }
  cout << "[ ";
  for (int num : result) {
    cout << num << ' ';
  }
  cout << "]\n";
  return;
}

int main() {
  Node *root = new Node(1,
                  new Node(2, new Node(4), new Node(5, new Node(6), new Node(7)))
                  , new Node(3, nullptr, new Node(8, new Node(9), nullptr)));
  printResult(1, preorderTraversal(root));
  printResult(2, inorderTraversal(root));
  printResult(3, postorderTraversal(root));
  return 0;
}
