#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findHeight(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int left = findHeight(root->left);
    if (left == -1)
    {
        return -1;
    }
    int right = findHeight(root->right);
    if (right == -1)
    {
        return -1;
    }

    if (abs(left - right) > 1)
    {
        return -1;
    }
    return 1 + max(left, right);
}

bool isBalanced(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    return findHeight(root) != -1;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);

    cout << isBalanced(root) << endl;
}