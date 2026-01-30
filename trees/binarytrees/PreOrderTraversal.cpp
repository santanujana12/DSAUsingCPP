#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

void preOrderHelper(TreeNode *root, std::vector<int> &result)
{
  if (root == nullptr)
  {
    return;
  }
  result.push_back(root->data);
  preOrderHelper(root->left, result);
  preOrderHelper(root->right, result);
}

vector<int> preOrderTraversal(TreeNode *root)
{
  vector<int> result;
  preOrderHelper(root, result);
  return result;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  vector<int> result = preOrderTraversal(root);
  cout << "Pre-order Traversal: [";
  for (size_t i = 0; i < result.size(); ++i)
  {
    cout << result[i] << (i < result.size() - 1 ? ", " : "");
  }
  cout << "]" << endl;
  return 0;
}
