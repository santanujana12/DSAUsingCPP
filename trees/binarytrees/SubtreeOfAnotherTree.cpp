#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isValidSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!root and !subRoot)
    {
        return true;
    }
    if (!root or !subRoot)
    {
        return false;
    }
    return (root->val == subRoot->val and isValidSubtree(root->left, subRoot->left) and isValidSubtree(root->right, subRoot->right));
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!subRoot)
    {
        return true;
    }
    if (!root)
    {
        return false;
    }
    if (isValidSubtree(root, subRoot))
    {
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode *subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    cout << isSubtree(root, subRoot) << endl;
}