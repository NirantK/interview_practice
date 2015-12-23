// ZIGZAGTREE
// https://www.interviewbit.com/courses/programming/topics/trees/problems/zigzagtree/
// What can we learn from the interviewbit solution? 1. Notice the clever use of stacks
// 2. Notice the completely iterative approach
// 3. Notice the updating of current_layer using the .swap function. I did not know about this. Can save so much code writing time. 
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
void printLevel(TreeNode* root, int level, vi &res){
	if(root==NULL)
		return;
	if(level==1)
		res.push_back(root->val);
	else if(level > 1){
		printLevel(root->left, level -1, res);
		printLevel(root->right, level -1, res);
	}
}
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
	vvi answer;
	vi res;
	int h = height(root);
	for (int i = 0; i <= h; ++i){
		res.clear();
		printLevel(root, i, res);
		if(i%2==0){
			reverse(res.begin(), res.end());
		}
		if(!res.empty())
			answer.push_back(res);
	}
	return answer;
}

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > output;
		if (root == NULL) return output;
		stack<TreeNode*> cur_layer;
		cur_layer.push(root);
		stack<TreeNode*> next_layer;
		vector<int> layer_output;
		int d = 0; // 0: left to right; 1: right to left.

		while (!cur_layer.empty()) {
			TreeNode* node = cur_layer.top();
			cur_layer.pop();
			layer_output.push_back(node->val);
			if (d == 0) {
				if (node->left != NULL) next_layer.push(node->left);
				if (node->right != NULL) next_layer.push(node->right);
			} else {
				if (node->right != NULL) next_layer.push(node->right);
				if (node->left != NULL) next_layer.push(node->left);
			}

			if (cur_layer.empty()) {
				output.push_back(layer_output);
				layer_output.clear();
				cur_layer.swap(next_layer);
				if (d == 1) d = 0;
				else d = 1;
			}
		}
		return output;
	}
};
int main(int argc, char const *argv[]){
	TreeNode* root = NULL;
	root = insert(root, 3);
	root->left = insert(root->left, 9);
	root->right = insert(root->right,20);
	root->right->left = insert(root->right->left, 15);
	root->right->right = insert(root->right->right, 7);
	vvi answer = zigzagLevelOrder(root);
	tr(answer, it){
		tr((*it), local_it){
			printf("%d ", (*local_it));
		}
		printf("==\n");
	}
	return 0;
}