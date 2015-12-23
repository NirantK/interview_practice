// LCA - Least Common Ancestor
// https://www.interviewbit.com/courses/programming/topics/trees/problems/lca/
// It is pure gold
// Interviewbit solution uses only recursion. It is way simpler than my approach. 
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

void inOrderPrint(TreeNode *root, int index){
	if(root == NULL) return;
	inOrderPrint(root->left, index+1);
	printf("%d", root->val);
	inOrderPrint(root->right, index+1);
}
int height(TreeNode*root){
	if(root==NULL)
		return 0;
	int l = height(root->left);
	int r = height(root->right);
	return max(l,r)+1;
}
bool findAncestors(TreeNode * root, int val, vi &ancestors){
	if(root==NULL) return false;

	if(root->val == val) {
		ancestors.push_back(val);
		return true;
	}
	bool l = findAncestors(root->left, val, ancestors);
	if(l ^ findAncestors(root->right, val, ancestors)){
		// printf("%d\n", root->val);
		ancestors.push_back(root->val);
		return true;
	}
	return false;
}

int lca(TreeNode* root, int val1, int val2) {
	vi firstAncestors;
	vi secondAncestors;
	bool firstVal = findAncestors(root, val1, firstAncestors);
	if(firstVal==false)
		return -1;
	bool secondVal = findAncestors(root, val2, secondAncestors);
	if(!secondVal)
		return -1;

	if (firstAncestors.size() > secondAncestors.size()){
		firstAncestors.swap(secondAncestors);
	}
	int sz = firstAncestors.size();
	for(int i = 0; i < sz ; ++i){
		for (int j = 0; j < secondAncestors.size(); ++j)
		{
			if(firstAncestors[i]==secondAncestors[j])
				return firstAncestors[i];	
		}
		// printf("%d %d\n", firstAncestors[i], secondAncestors[i]);
	}
	return 0;
}
// INTERVIEWBIT SOLUTION
class Solution {
    public:
    	// NK: This helper function is gold. Not the clever return at the last to eliminate entire subtrees
        TreeNode *LCA(TreeNode *root, int val1, int val2) {
            if (!root) return NULL;
            if (root->val == val1 || root->val == val2) return root;
            TreeNode *L = LCA(root->left, val1, val2);
            TreeNode *R = LCA(root->right, val1, val2);
            if (L && R) return root; // If val1, val2 are on both sides 
            return L ? L : R; // either one of val1, val2 is on one side OR val1, val2 is not in L&R subtrees
        }

        bool find(TreeNode *root, int val1) {
            if (!root) return false;
            if (root->val == val1) return true;
            return (find(root->left, val1) || find(root->right, val1));
        }

        int lca(TreeNode *root, int val1, int val2) {
            if (!find(root, val1) || !find(root, val2)) return -1;
            TreeNode *ans = LCA(root, val1, val2);
            if (!ans) return -1;
            return ans->val;
        }
};
int main(int argc, char const *argv[]){
	TreeNode* root = NULL;
	root = insert(root, 3);
	root->left = insert(root->left, 9);
	root->left->left = insert(root->left->left, 11);
	root->left->right = insert(root->left->right, 2);
	root->right = insert(root->right,20);
	root->right->left = insert(root->right->left, 15);
	root->right->right = insert(root->right->right, 7);
	// vvi answer = zigzagLevelOrder(root);
	printf("Answer: %d\n", lca(root, 15, 7));
	// printf("-------%d\n", height(root));
	// inorderTraversal(root);
	return 0;
}