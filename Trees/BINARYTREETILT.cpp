// LEETCODE CONTEST29 PROBLEM
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
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
	}else if(root->val < x){
		root->left = insert(root->left, x);
	}else{
		root->right = insert(root->right, x);
	}
	return root;
}
void inorderPrint(TreeNode *root){
	if(root == NULL) return;
	inorderPrint(root->left);
	printf("%d\n", root->val);
	inorderPrint(root->right);
}

void postOrderPrint(TreeNode* root){
	if(root == NULL) return;
	printf("%d\n", root->val);
	postOrderPrint(root->left);
	postOrderPrint(root->right);
}

void preOrderPrint(TreeNode* root){
	if(root == NULL) return;
	preOrderPrint(root->left);
	preOrderPrint(root->right);
	printf("%d\n", root->val);
} 

int sumTree(TreeNode* root){
	if(root == NULL) return 0;
	return sumTree(root->left) + sumTree(root->right) + root->val;
}

int findTilt(TreeNode* root) {
	if (root == NULL){
		return 0;
	}
	// printf("Node: %d\n", root->val);
	int left = findTilt(root->left);
	// printf("Left tilt sum: %d\n", left);
	int right = findTilt(root->right);
	// printf("Left right sum: %d\n", right);
	int self = abs(sumTree(root->right) - sumTree(root->left));
	// printf("Self: %d\n\n", self);
	return left + right + self;
}

int main(int argc, char const *argv[]){
	// vi x = {1,5,3,4,2};
	vi x = {1, 2, 3, 4, 0, 5};
	TreeNode* root = NULL;
	root = (TreeNode*) new TreeNode(1);
	root->left = (TreeNode*) new TreeNode(2);
	root->right = (TreeNode*) new TreeNode(3);
	root->left->left = (TreeNode*) new TreeNode(4);
	root->right->left = (TreeNode*) new TreeNode(5);
	// for (int i = 0; i < x.size(); ++i)
	// {
	// 	root = insert(root, x[i]);
	// }
	printf("insert completed\n");
	printf("%d\n", findTilt(root));
	return 0;
}