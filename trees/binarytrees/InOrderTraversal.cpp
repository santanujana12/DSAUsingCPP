#include <iostream>
#include <vector>

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inOrderHelper(TreeNode *root, std::vector<int> &result) {
  if (root == nullptr) {
    return;
  }
  inOrderHelper(root->left, result);
  result.push_back(root->data);
  inOrderHelper(root->right, result);
}

std::vector<int> inOrderTraversal(TreeNode *root) {
  std::vector<int> result;
  inOrderHelper(root, result);
  return result;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  std::vector<int> result = inOrderTraversal(root);

  std::cout << "In-order Traversal: [";
  for (size_t i = 0; i < result.size(); ++i) {
    std::cout << result[i] << (i < result.size() - 1 ? ", " : "");
  }
  std::cout << "]" << std::endl;

  return 0;
}
