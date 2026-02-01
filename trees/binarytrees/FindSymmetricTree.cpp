#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool findIsSymmetric(TreeNode *left, TreeNode *right)
{
    if (!left and !right)
    {
        return true;
    }
    if (!left || !right)
    {
        return false;
    }

    return left->data == right->data and findIsSymmetric(left->left, right->right) and findIsSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL or (!root->left and !root->right))
    {
        return true;
    }

    return findIsSymmetric(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // root->right->left is null
    // root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(8);

    // children of node 5
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    // child of node 8
    root->right->right->left = new TreeNode(9);

    cout << isSymmetric(root) << endl;
}