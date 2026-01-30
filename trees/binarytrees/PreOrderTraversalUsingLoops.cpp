#include <iostream>
#include <stack>
#include <vector>


struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

std::vector<int> preorderTraversal(TreeNode *root) {
  if (root == nullptr) {
    return {};
  }

  std::vector<int> res;
  std::stack<TreeNode *> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode *curr = st.top();
    st.pop();
    res.push_back(curr->data);

    // Push right first so left is processed first
    if (curr->right != nullptr) {
      st.push(curr->right);
    }
    if (curr->left != nullptr) {
      st.push(curr->left);
    }
  }

  return res;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(6);
  root->left->right->right = new TreeNode(7);
  root->right->right->left = new TreeNode(9);

  std::vector<int> result = preorderTraversal(root);
  for (int i : result) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
