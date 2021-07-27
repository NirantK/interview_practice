// BALANCED
// https://www.interviewbit.com/courses/programming/topics/trees/problems/balanced/
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
	}else if(root->val > x){
		root->left = insert(root->left, x);
	}else{
		root->right = insert(root->right, x);
	}
	return root;
}
void inorderPrint(TreeNode *root){
	if(root == NULL) return;
	inorderPrint(root->left);
	printf("%d ", root->val);
	inorderPrint(root->right);
}

void postOrderPrint(TreeNode* root){
	if(root == NULL) return;
	printf("%d ", root->val);
	postOrderPrint(root->left);
	postOrderPrint(root->right);
}
void preOrderPrint(TreeNode* root){
	if(root == NULL) return;
	preOrderPrint(root->left);
	preOrderPrint(root->right);
	printf("%d ", root->val);
}

TreeNode* invertTree(TreeNode* node) {
    if(!node) return node;
	node->left = invertTree(node->left);
	node->right = invertTree(node->right);

	TreeNode *temp = node->left;
	node->left = node->right;
	node->right = temp;
	return node;
}
int main(int argc, char const *argv[]){
	vi x = {1,5,3,4,2, 6, 7};
	TreeNode* root = NULL;
	for (int i = 0; i < x.size(); ++i)
	{
		root = insert(root, x[i]);
	}
	postOrderPrint(root);
	printf("\n"); root = invertTree(root);
	postOrderPrint(root);
	// preOrderPrint(root);
	return 0;
}