// https://www.interviewbit.com/courses/programming/topics/trees/problems/prefix/?ref=dash-reco
// PREFIX - Question asked in the fearsome Google, adn rightly so
// The real genius of this solution is lies using two vvi as a trie and the frequency counter. 
// It has critical advantages: 1. Easier to understand mentally. 2. Less memory 
// 3. Easier to debug that trie with pointers all over the place. 
// Some simple ideas are really beautiful, look at the prefix function init lines: 
	// Trie.resize(N * mx_len + 1, vector<int>(27, -1));
	// Cnt.resize(N * mx_len + 1, vector<int>(27, -1));
// I have no fucking clue how vi(27, -1) works or what it does. 
// Edit: that in particular declares a vi of size=27 elements all initialised to -1, instead of the usual zero. 

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

class Solution {
	public:
	int IDX;
	vector<vector<int> > Cnt;
	vector<vector<int> > Trie;
	
	void insert(string str)
	{
		int len = str.size();
		int root = 0;
		int i = 0;

		while(i < len) {
			int chr = str[i] - 'a';
			if(Trie[root][chr] == -1) {
				++IDX;
				Trie[root][chr] = IDX;
				Cnt[root][chr] = 1;
			} else {
				Cnt[root][chr]++;
			}
			root = Trie[root][chr];
			i++;
		}
	}

	string Query(string str) 
	{
		int root = 0;
		string ans = "";
		int i = 0;
		int len = str.size();

		while(i < len) {
			int chr = str[i] - 'a';
			ans += str[i];
			if(Cnt[root][chr] == 1)
					return ans;
			root = Trie[root][chr];
			i++;
		}
		return "";
	}

	vector<string> prefix(vector<string> Vec)
	{
		int mx_len = 0;
		int N = Vec.size();
		for(int i = 0; i < N; ++i) {
			mx_len = max(mx_len, (int)Vec[i].size());
		}

		Trie.clear();
		Cnt.clear();
		Trie.resize(N * mx_len + 1, vector<int>(27, -1));
		Cnt.resize(N * mx_len + 1, vector<int>(27, -1));
		IDX = 0;

		for(int i = 0; i < N; ++i) {
			insert(Vec[i]);
		} 

		vector<string> Ans;
		for(int i = 0; i < N; ++i) {
			string ans = Query(Vec[i]);
			Ans.push_back(ans); 
		}

		return Ans;
	}
};

int main(int argc, char const *argv[]){
	vs input = {"zebra", "dog", "duck", "dove"};
	input = {"zebra", "dog", "duck", "dot"};
	Solution s ;
	vs answer = s.prefix(input);
	printf("\nReturned: ");
	tr(answer, it){
		printf("%s ", (*it).c_str());
	}
	printf("\nExpected: z dog du dot");
	// Print all prefixes using Trie Traversal
	// inOrderPrint(root);
	// printf("\n%d", isSymmetric(root));
	return 0;
}