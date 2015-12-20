// MERGEKLIST
// https://www.interviewbit.com/courses/programming/topics/heaps-and-maps/problems/mergeklist/

// interviewbit used a priority queue, I solved this using a map
// after solving this, I realised I could have simply used a vi to store the elements instead of map
// hence, two things pending - despite solving this question correctly and before average time
//  1. Solve using vi, 2. Solve using priority queue
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

int max_height(TreeNode* node){
	if(node==NULL)
		return 0;
	else
		return 1+max(max_height(node->left), max_height(node->right));
}
int min_height(TreeNode* node, int h){
	if(node==NULL)
		return 0;
	else
		return 1+min(max_height(node->left), max_height(node->right));
}
int maxDepth(TreeNode * root){
        if (root==NULL){return 0;}
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    int minDepth(TreeNode * root){
        if (root==NULL){return 0;}
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxd = maxDepth(root);
        int mind = minDepth(root);
        if (abs(maxd-mind)<=1) {return true;} else {return false;}
    }

int isBalanced(TreeNode* A) {
	int max_h = max_height(A);
	int min_h = min_height(A);
	if(abs(max_h-min_h)<=1) return 1;
	return 0;
}
int main(int argc, char const *argv[]){
	return 0;
}