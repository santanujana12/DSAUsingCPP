#include<bits/stdc++.h>
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

int matchCount  = 0;
pair<int, int> calculateAverage(TreeNode* root, int sum) {
    if (root == NULL) {
        return {0, 0};
    }
    pair<int, int> left = calculateAverage(root->left, sum);
    pair<int, int> right = calculateAverage(root->right, sum);

    sum = left.first + right.first + root->val;
    int nodeCount = left.second + right.second + 1;
    int average = sum / nodeCount;
    if (average == root->val) {
        matchCount ++;
    }
    return {sum, nodeCount};
}

int averageOfSubtree(TreeNode* root) {
    if (!root->left and !root->right) {
        return 1;
    }
    calculateAverage(root, 0);
    return matchCount ;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << averageOfSubtree(root) << endl;
}
