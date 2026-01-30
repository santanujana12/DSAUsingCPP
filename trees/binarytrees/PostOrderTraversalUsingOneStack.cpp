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
  std::stack<TreeNode *> st;

  TreeNode *curr = root;
  TreeNode *isVisited = nullptr;

  while (curr != nullptr || !st.empty()) {
    while (curr != nullptr) {
      st.push(curr);
      curr = curr->left;
    }

    TreeNode *peekNode = st.top();

    if (peekNode->right != nullptr && peekNode->right != isVisited) {
      curr = peekNode->right;
    } else {
      ans.push_back(peekNode->data);
      isVisited = peekNode;
      st.pop();
    }
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

  for (int val : result) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
  return 0;
}
