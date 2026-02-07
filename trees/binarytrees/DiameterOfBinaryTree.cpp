// Input and print written in the header file
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printBinaryTreeBFS(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
}

int findHeight(TreeNode *root, int &diameter)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = findHeight(root->left, diameter);
    int right = findHeight(root->right, diameter);
    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int diameter = 0;
    int ht = findHeight(root, diameter);
    return diameter;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(9);
    // The tree structure is now set up for further operations.

    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}