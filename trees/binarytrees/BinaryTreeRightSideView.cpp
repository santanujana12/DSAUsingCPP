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

vector<int> rightSideView(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<int> res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        // int i=0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (i == 0)
            {
                res.push_back(curr->val);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
            // i++;
        }
    }

    return res;
}

void traverse(TreeNode *root, vector<int> &res, int level)
{
    if (!root)
    {
        return;
    }
    if (level == res.size())
    {
        res.push_back(root->val);
    }
    traverse(root->right, res, level + 1);
    traverse(root->left, res, level + 1);
}

vector<int> rightSideViewRec(TreeNode *root)
{
    if (!root)
    {
        return {};
    }
    vector<int> res;
    traverse(root, res, 0);
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    // root->left->right->left = new TreeNode(7);
    // root->left->right->right = new TreeNode(4);
    // root->right->right = new TreeNode(4);

    vector<int> rightView = rightSideViewRec(root);

    for (auto i : rightView)
    {
        cout << i << " ";
    }
    cout << endl;
}