#include <iostream>
#include <stack>
#include <vector>


struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

std::vector<int> postorderTraversal(TreeNode *root) {
  if (root == nullptr) {
    return {};
  }

  std::vector<int> ans;
  std::stack<TreeNode *> s1;
  std::stack<int> s2;

  s1.push(root);

  while (!s1.empty()) {
    TreeNode *curr = s1.top();
    s1.pop();
    s2.push(curr->data);

    if (curr->left != nullptr) {
      s1.push(curr->left);
    }
    if (curr->right != nullptr) {
      s1.push(curr->right);
    }
  }

  while (!s2.empty()) {
    ans.push_back(s2.top());
    s2.pop();
  }

  return ans;
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

  std::vector<int> result = postorderTraversal(root);
  for (int i : result) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
