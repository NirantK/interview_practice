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
vector<int> inorderTraversal(TreeNode* root){
	vector<int> answer;
	TreeNode* current = root;
	TreeNode* pre;
	while(current!=NULL){
		if(current->left==NULL){
			// printf("%d\n", current->val);
			answer.push_back(current->val);
			current = current->right;
		}
		else{
			pre = current -> left;
			while(pre->right!=NULL && pre->right !=current){
				pre = pre->right;
			}

			if(pre->right == NULL){
				pre->right = current;
				current = current -> left;
			}else{ // pre->right == current is true here
				pre->right == NULL;
				// printf("%d\n", current->val);
				answer.push_back(current->val)
				current = current ->right;
			}

		}
	}
	return answer;
}

void inOrderPrint(TreeNode *root){
	if(root == NULL) return;
	inOrderPrint(root->left);
	printf("%d ", root->val);
	inOrderPrint(root->right);
}


// INTERVIEWBIT Solution
// Pretty neat, does not alter the tree and is 'simple'
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;

        while(!stack.empty() || pCurrent)
        {
            if(pCurrent)
            {
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else
            {
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }
};

int main(int argc, char const *argv[]){
	TreeNode* root = NULL;
	root = insert(root, 1);
	root->left = insert(root->left, 2);
	root->left->left = insert(root->left->left, 3);
	root->left->left->left = insert(root->left->left->left, 4);
	root->left->right = insert(root->left->right, 5);
	root->right = insert(root->right,6);
	root->right->left = insert(root->right->left, 7);
	root->right->right = insert(root->right->right, 8);
	root->right->right->right = insert(root->right->right->right, 9);
	inOrderPrint(root);
	inorderTraversal(root);
	return 0;
}