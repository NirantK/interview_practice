#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
void preOrderPrint(TreeNode* root){
	if(root == NULL) return;
	preOrderPrint(root->left);
	preOrderPrint(root->right);
	printf("%d ", root->val);
}

/*****************************************/
// https://www.interviewbit.com/courses/programming/topics/trees/problems/cartesian/
// CARTESIAN

// My solution is same as Interviewbit. committed really silly mistakes here, which led to loss of atleast 225 points. 
// Silly mistakes like: forgetting equality in for loop, updating left instead of right and vice versa in the end part and so on. 
/******************************************/

TreeNode* cartesian(vector<int> &A, int start, int end){
	if(start ==  end) return new TreeNode(A[start]);
	if(start > end) return NULL;

	int maxVal = INT_MIN;
	int maxPos = -1;

	for (int i = start; i <= end; ++i){
		if(A[i] > maxVal){
			maxVal = A[i];
			maxPos = i;
		}
	}
	// printf("\nInserting %d", maxVal);
	TreeNode* root = new TreeNode(maxVal);
	root->left = cartesian(A, start, maxPos-1);
	root->right = cartesian(A, maxPos + 1, end);
	return root;
}


TreeNode* buildTree(vector<int> &A) {
	if(A.size()==0) return NULL;
	return buildATree(A, 0, A.size()-1);
}

int main(int argc, char const *argv[]){
	vi x = {5, 10, 40, 30, 28};
	x = {1,2,3};
	// TreeNode* root = NULL;
	// for (int i = 0; i < x.size(); ++i)
	// {
		// root = insert(root, x[i]);
	// }
	// inOrderPrint(root);
	// kthsmallest(root ,2);
	TreeNode* root = buildTree(x);
	printf("\nReturned: "); preOrderPrint(root);
	return 0;
}