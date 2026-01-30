#include <iostream>
#include <stack>
#include <vector>


struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

std::vector<int> inorderTraversal(TreeNode *root) {
  std::vector<int> ans;
  if (root == nullptr) {
    return ans;
  }

  std::stack<TreeNode *> st;
  TreeNode *curr = root;

  while (curr != nullptr || !st.empty()) {
    while (curr != nullptr) {
      st.push(curr);
      curr = curr->left;
    }

    curr = st.top();
    st.pop();
    ans.push_back(curr->data);
    curr = curr->right;
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

  std::vector<int> result = inorderTraversal(root);
  for (int i : result) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
