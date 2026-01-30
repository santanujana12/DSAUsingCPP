#include <iostream>
#include <queue>
#include <vector>


struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrderTraversal(TreeNode *root) {
  std::vector<std::vector<int>> result;

  if (root == nullptr) {
    return result;
  }

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = q.size();
    std::vector<int> level;

    for (int i = 0; i < levelSize; i++) {
      TreeNode *curr = q.front();
      q.pop();
      level.push_back(curr->data);

      if (curr->left != nullptr) {
        q.push(curr->left);
      }
      if (curr->right != nullptr) {
        q.push(curr->right);
      }
    }
    result.push_back(level);
  }

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

  std::vector<std::vector<int>> result = levelOrderTraversal(root);

  for (const auto &level : result) {
    for (int val : level) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
