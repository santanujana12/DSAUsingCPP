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

int globalMaxSum = INT_MIN;

int findMaxPathSum(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int maxLeftSum = max(0, findMaxPathSum(root->left));
    int maxRightSum = max(0, findMaxPathSum(root->right));

    int currentSum = root->val + maxLeftSum + maxRightSum;
    globalMaxSum = max(currentSum, globalMaxSum);

    return root->val + max(maxLeftSum, maxRightSum);
}

int maxPathSum(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    findMaxPathSum(root);
    return globalMaxSum;
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
    cout << maxPathSum(root) << endl;
}