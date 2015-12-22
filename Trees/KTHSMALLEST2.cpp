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
// INTERVIEWBIT SOLUTION (find function)
// https://www.interviewbit.com/courses/programming/topics/trees/problems/kthsmallest2/
// Has the advantage that this is does not use O(k) space 
// which my solution (search function) does
int find(TreeNode* root, int &k) {
	if (!root) return -1;
	// We do an inorder traversal here. 
	int k1 = find(root->left, k);
	if (k == 0) return k1; // left subtree has k or more elements.
	k--; 
	if (k == 0) return root->val; // root is the kth element.
	return find(root->right, k); // answer lies in the right node.
}
/******************************************/

void search(TreeNode* root, vi &answer){
	if(root==NULL) return;
	search(root->left, answer);
	answer.push_back(root->val);
	search(root->right, answer);
}

int kthsmallest (TreeNode* root, int k) {
	vi answer;
	search(root, answer);
	// tr(answer, it)
		// printf("%d ", (*it));

	return answer[k-1];
}

int main(int argc, char const *argv[]){
	vi x = {2,1,3};
	TreeNode* root = NULL;
	for (int i = 0; i < x.size(); ++i)
	{
		root = insert(root, x[i]);
	}
	inOrderPrint(root);
	kthsmallest(root ,2);
	return 0;
}