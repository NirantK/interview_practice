// https://www.interviewbit.com/courses/programming/topics/trees/problems/prefix/?ref=dash-reco
// PREFIX - Question asked in the fearsome Google, adn rightly so
// I did get it correct, learning a lot of pointers, printf degbugging and most important, the idea of tries.
// My solution gets a memory limit exceeded. I have no clue why. Look for interviewbit solution in another file.
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

#define MAX 256
#define MAX_WORD_LEN 50
struct TrieNode {
	int freq;
	TrieNode* child[MAX] ;
};
TrieNode *newTrieNode(){
	TrieNode *newNode = new TrieNode();
	newNode->freq   = 1;
	for (int i = 0; i<MAX; i++)
		newNode->child[i] = NULL;
	return newNode;
}
void traverse(TrieNode* root){
	TrieNode* temp = root;
	if(root==NULL) return;
	for (int i = 0; i < MAX; ++i)
	{
		if (temp->child[i]!=NULL)
		{
			printf("%c", (char)i);
			traverse(temp->child[i]);
		}
	}
}

void findPrefixesUtil(TrieNode * root, char prefix[], int ind, vs & answer) {
    // Corner case
    if (root == NULL)
        return;

    // Base case
    if (root -> freq == 1) {
        prefix[ind] = '\0';
        // cout << prefix << " ";
        string res = prefix;
        // printf("%s ", res.c_str());
        answer.insert(answer.begin(), res);
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (root -> child[i] != NULL) {
            prefix[ind] = i;
            // printf("%c\n", i);
            findPrefixesUtil(root -> child[i], prefix, ind + 1, answer);
        }
    }
}
void insert(TrieNode* root, string word){
	TrieNode* temp = root;
	for (int i = 0; i < word.length(); ++i){
		int index = word[i]; // typecast to an integer, which can be looked up 
		// printf("\nIndex: %d", index);
		if(temp->child[index]==NULL){
			temp->child[index] = newTrieNode();
			// printf("\ntemp->child[index] %c : temp->freq %d", index, temp->freq);

		}
		else{
			// printf("\nFrequency of %d is %d", index, temp->child[index]->freq);
			++(temp->child[index]->freq);
		}
		temp = temp->child[index];
	}
}

string findPrefixHelper(TrieNode* root, string word){
	TrieNode* temp = root;
	string answer;
	for (int i = 0; i < word.length(); ++i){
		int index = word[i]; // typecast to an integer, which can be looked up 
		if (temp->child[index]!=NULL){
			temp = temp->child[index];
			if(temp->child[index]->freq==1){
				answer += word[i];
				return answer;
			}
			answer += word[i];		
		}
	}
	return answer;
}

vector<string> prefix(vector<string> &input) {
	TrieNode *root = newTrieNode();
	root->freq = 0;
	for (int i = 0; i<input.size(); i++)
		insert(root, input[i]);
	vs answer;
	for (int i = 0; i < input.size(); ++i){
		answer.push_back(findPrefixHelper(root, input[i]));
	}
	return answer;
}

int main(int argc, char const *argv[]){
	vs input = {"zebra", "dog", "duck", "dove"};
	input = {"zebra", "dog", "duck", "dot"};
	vs answer = prefix(input);
	tr(answer, it){
		printf("%s ", (*it).c_str());
	}
 	printf("\nExpected: z dog du dot");
	return 0;
}