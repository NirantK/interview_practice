// FLATTEN
// https://www.interviewbit.com/courses/programming/topics/trees/problems/flatten 
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <limits.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define pb push_back
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* insert(TreeNode* root, int x){
	if(root==NULL){
		root = (TreeNode*) new TreeNode(x);
		// root = temp;
	}else if(root->val > x){
		root->left = insert(root->left, x);
	}else{
		root->right = insert(root->right, x);
	}
	return root;
}

void inOrderPrint(TreeNode *root){
	if(root == NULL) return;
	inOrderPrint(root->left);
	printf("%d ", root->val);
	inOrderPrint(root->right);
}

void postOrderPrint(TreeNode* root){
	if(root == NULL) return;
	printf("%d ", root->val);
	postOrderPrint(root->left);
	postOrderPrint(root->right);
}
void preOrderPrint(TreeNode *root){
	if(root == NULL) return;
	printf("%d", root->val);
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}
int height(TreeNode*root){
	if(root==NULL)
		return 0;
	int l = height(root->left);
	int r = height(root->right);
	return max(l,r)+1;
}
TreeNode* flatten(TreeNode* node) {
	TreeNode* root = node;
	if(root == NULL) return root;
	TreeNode* pre;
	while(root!=NULL){
		if(root->left){
			pre = root -> left;
			while(pre->right != NULL)
				pre = pre->right;
			pre->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		root = root -> right;
	}
	return node;
}
int main(int argc, char const *argv[]){
	TreeNode* root = NULL;
	root = insert(root, 1);
	root->left = insert(root->left, 2);
	root->left->left = insert(root->left->left, 3);
	root->left->right = insert(root->left->right, 4);
	root->right = insert(root->right,5);
	// root->right->left = insert(root->right->left, 15);
	root->right->right = insert(root->right->right, 6);
	inOrderPrint(root);
	root = flatten(root);
	printf("\nflattened: ");
	inOrderPrint(root);
	return 0;
}