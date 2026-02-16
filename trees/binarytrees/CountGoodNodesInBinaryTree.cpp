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

void countGoodNodes(TreeNode *root, int maxValue, int &count)
{
    if (!root)
    {
        return;
    }

    if (root->val >= maxValue)
    {
        maxValue = root->val;
        count++;
    }
    countGoodNodes(root->left, maxValue, count);
    countGoodNodes(root->right, maxValue, count);
}

int goodNodes(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int count = 0;
    countGoodNodes(root, root->val, count);
    return count;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    // root->left->right->left = new TreeNode(7);
    // root->left->right->right = new TreeNode(4);
    // root->right->right = new TreeNode(4);

    cout << goodNodes(root) << endl;
}