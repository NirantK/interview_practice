// ORDER - Google Question
// I solved this in O(n^2) which was accepted. Interviewbit has a way to solve this in O(n logn) using segment trees.
// I dont have the patience to learn segment trees right now. Hence, skipped for now. 
// Check the interviewbit solution here: https://www.interviewbit.com/courses/programming/topics/trees/problems/order/
// (It is not in this file)
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
// typedef vector<string> vs;
// typedef vector<vs> vvs;
#define pb push_back
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)

vector<int> order(vector<int> &heights, vector<int> &infronts) {
	int sz = heights.size();
	vi answer(sz, -1);
	map<int, int> mymap;
	for (int i = 0; i < sz; ++i){
		mymap[heights[i]] = infronts[i];
	}
	// tr(mymap, it){
	// 	printf("%d:%d\n", it->first, it->second);
	// }
	int count;
	tr(mymap, it){
		count = -1;
		for (int i = 0; i < sz; ++i){
			if(answer[i]==-1)
				++count;
			// printf("Vacant: %d out of %d ; need %d vacant for %d \n", count, i, it->second, it->first);
			if(count==it->second){
				answer[i]=it->first;
				break;
			}
		}
	}
	return answer;
}

int main(int argc, char const *argv[]){
	vi heights = {5, 3, 2, 6, 1, 4};
	vi infronts = {0, 1, 2, 0, 3, 2};
	vi answer = order(heights, infronts);
	printf("\n");
	tr(answer, it){
		printf("%d ", (*it));
	}
	return 0;
}