// DNUMS
// https://www.interviewbit.com/courses/programming/topics/heaps-and-maps/problems/dnums/?ref=dash-reco

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
// interviewbit and my solution are the same. Yay! 
// interesting question where hashmap is used as a queue in a sliding window fashion
// if we used two vi's or any other data structure to force traversal on the k-sized window, 
// we get a TLE
vector<int> dNums(vector<int> &A, int k) {
	vi answer;
	map<int, int> mymap;
	if(k > A.size()) return answer;
	for (int i = 0; i < A.size(); ++i){
		int j = i-k+1;
		++mymap[A[i]];
		if(j>=0){
			answer.push_back(mymap.size());
			mymap[A[j]]--;
			if(mymap[A[j]]==0) mymap.erase(A[j]);
		}
	}
	return answer;
}

int main(int argc, char const *argv[]){
	vi input = {1, 2, 1, 3, 4, 3};
	int k  = 3;
	vi answer = dNums(input, 3);
	// printf("%d\n", );
	tr(answer, it){
		printf("%d ", (*it));
	}
	return 0;
}