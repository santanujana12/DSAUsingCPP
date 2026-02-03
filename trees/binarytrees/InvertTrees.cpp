// Input and print written in the header file
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printBinaryTreeBFS(TreeNode *root){
	if(root==NULL){
		return;
	}
	
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty()){
		TreeNode *curr = q.front();
		q.pop();
		cout<<curr->val<<" ";
		if(curr->left){
			q.push(curr->left);
		}
		if(curr->right){
			q.push(curr->right);
		}
	}
}

TreeNode* invertTree(TreeNode* root) {
    if(root==NULL){
    	return NULL;
    }
    queue<TreeNode*>q;
   	q.push(root);
    while(!q.empty()){
    	TreeNode *curr = q.front();
    	q.pop();
    	swap(curr->left,curr->right);
    	if(curr->left){
    		q.push(curr->left);
    	}
    	if(curr->right){
    		q.push(curr->right);
    	}
    }
    return root;
}


int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    // The tree structure is now set up for further operations.

    TreeNode *invertedTree = invertTree(root);
    printBinaryTreeBFS(invertedTree);
    return 0;
}