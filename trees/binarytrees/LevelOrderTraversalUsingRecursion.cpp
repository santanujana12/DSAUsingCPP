#include <iostream>
#include <vector>

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> result;

void traversalDFS(TreeNode *root, int level) {
  if (root == nullptr) {
    return;
  }

  if (level == result.size()) {
    result.push_back({});
  }

  result[level].push_back(root->data);

  traversalDFS(root->left, level + 1);
  traversalDFS(root->right, level + 1);
}

std::vector<std::vector<int>> levelOrderTraversal(TreeNode *root) {
  if (root == nullptr) {
    return {};
  }
  result.clear();
  traversalDFS(root, 0);
  return result;
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

  std::vector<std::vector<int>> res = levelOrderTraversal(root);

  for (const auto &level : res) {
    for (int val : level) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
