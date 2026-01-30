#include <algorithm>
#include <iostream>


struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  return std::max(leftDepth, rightDepth) + 1;
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

  int depth = maxDepth(root);
  std::cout << "Maximum Depth of the Binary Tree: " << depth << std::endl;
  return 0;
}
