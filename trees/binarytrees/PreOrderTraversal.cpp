#include <iostream>
#include <vector>

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preOrderHelper(TreeNode *root, std::vector<int> &result) {
  if (root == nullptr) {
    return;
  }
  result.push_back(root->data);
  preOrderHelper(root->left, result);
  preOrderHelper(root->right, result);
}

std::vector<int> preOrderTraversal(TreeNode *root) {
  std::vector<int> result;
  preOrderHelper(root, result);
  return result;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  std::vector<int> result = preOrderTraversal(root);

  std::cout << "Pre-order Traversal: [";
  for (size_t i = 0; i < result.size(); ++i) {
    std::cout << result[i] << (i < result.size() - 1 ? ", " : "");
  }
  std::cout << "]" << std::endl;
  return 0;
}
