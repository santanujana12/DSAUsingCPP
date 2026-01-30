#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
	if(root==NULL){
		return false;
	}
	if(!root->left and !root->right){
		return root->val==targetSum;
	}
	
	int left = hasPathSum(root->left,targetSum-root->val);
	int right = hasPathSum(root->right,targetSum-root->val);
	// Find isLeaf
	return (left || right);
}


int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    int targetSum = 22;
    // The tree structure is now set up for further operations.

    cout<<hasPathSum(root, targetSum)<<endl;
    return 0;
}