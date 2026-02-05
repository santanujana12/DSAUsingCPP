#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode *leftInverted = invertTree(root->left);
    TreeNode *rightInverted = invertTree(root->right);

    root->left = rightInverted;
    root->right = leftInverted;

    return root;
}

TreeNode *invertTreeIterative(TreeNode *root)
{
    if (root == NULL){
        return NULL;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        swap(curr->left, curr->right);
        if (curr->left){
            q.push(curr->left);
        }
        if (curr->right){
            q.push(curr->right);
        }
    }
    return root;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode *invertedRoot = invertTreeIterative(root);
    // Or use the iterative version:
    // TreeNode *invertedRoot = invertTreeIterative(root);

    return 0;
}