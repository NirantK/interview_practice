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


// INTERVIEWBIT SOLUTION cos I did not keep my cool and lost points. I coulf have done this if I had kept my cool. 
pair<int, bool> isBalancedWithDepth(TreeNode *root) {
    if (root == NULL) return make_pair(0, true);
    pair<int, bool> left = isBalancedWithDepth(root->left);
    pair<int, bool> right = isBalancedWithDepth(root->right);
    int depth = max(right.first, left.first) + 1;
    // The subtree is balanced if right subtree is balanced, left subtree is balanced 
    // and the depth difference is less than 1. 
    bool isbalanced = right.second && left.second && (abs(right.first - left.first) < 2);
    return make_pair(depth, isbalanced);
} 


int Solution::isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        return isBalancedWithDepth(root).second;
    }
int main(int argc, char const *argv[]){
	vi x = {1,5,3,4,2};
	TreeNode* root = NULL;
	for (int i = 0; i < x.size(); ++i)
	{
		root = insert(root, x[i]);
	}
	// postOrderPrint(root);
	// preOrderPrint(root);
	return 0;
}