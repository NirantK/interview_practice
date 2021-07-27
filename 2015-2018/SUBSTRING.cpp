// https://www.interviewbit.com/courses/programming/topics/hashing/problems/substring/

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
vector<int> findSubstring(string A, const vector<string> &B) {
	vi answer;
	int n = B.size();
	if(0==n) return answer;
	int m = B[0].size();
	unordered_map <string, int> map;
	for (int i = 0; i < n; ++i){
		map[B[i]]++;
		// printf("%s\n", B[i].c_str());
	}
	for (int i = 0; i + n*m-1 < A.size(); ++i){
		unordered_map <string, int> hashmap;
		int j = 0;
		for (; j < n; ++j){
			string subs = A.substr(i+j*m, m);
			// printf("%s", subs.c_str());
			if(map.find(subs)==map.end()){
				// printf(" not found\n");
				break;
			}
			else{
				// printf(" found at %d\n", i);
				hashmap[subs]++;
				if(hashmap[subs] > map[subs])
					break;
			}
		}
		if(j==n) answer.push_back(i);
	}
	return answer;
}


int main(int argc, char const *argv[]){
	string A = "barfoothefoobarman";
	vs input = {"foo", "bar"};
	vi answer = findSubstring(A, input);
	tr(answer, it){
		printf("%d\n", (*it));
	}
	return 0;
}