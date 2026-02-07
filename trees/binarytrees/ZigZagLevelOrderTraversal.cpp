#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        vector<int> eachLevel;
        int qsize = q.size();

        for (int i = 0; i < qsize; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            eachLevel.push_back(curr->data);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        if (level % 2 != 0)
        {
            reverse(eachLevel.begin(), eachLevel.end());
        }
        level++;
        result.push_back(eachLevel);
    }
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // root->right->left is null
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(8);

    // children of node 5
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    // child of node 8
    root->right->right->left = new TreeNode(9);

    vector<vector<int>> result = zigzagLevelOrder(root);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}