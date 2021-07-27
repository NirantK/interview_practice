// ADJACENT
// https://www.interviewbit.com/courses/programming/topics/dynamic-programming/problems/adjacent/
// Again, a simple DP problem which I could not do. 
// But I saw the algorithm and made some points in this one. 
// I have seen the recursive solution, 
// and now trying the iterative one on my own.
// I think the main advantage of recursive approach is
// simpler base and edge cases
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <cassert>
#include <limits.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
int getSum(vector<vector<int> > &A, vi &dp, int c){
	// int sz = A[0].size();
	if(c<0) return 0;
	if(dp[c]!=-1) return dp[c];
	int thisCol = max(A[0][c], A[1][c]);
	int adjacent = max(thisCol+getSum(A, dp, c-2),  getSum(A, dp, c-1));
	return dp[c] = adjacent;
}

int adjacent(vector<vector<int> > &A) {
	vi dp(1000000, -1);
	return getSum(A, dp, A[0].size()-1);
}

int iterative(const vvi &A){
	vvi dp(A[0].size(), vi(2, -1));
	// vvi dp(100000, vi(-1));
	// dp[0][0] = max(A[0][0]);
	return 0;	
}
int main(int argc, char const *argv[]){
	vector<vector<int> > input = {	{1, 2, 3, 4, 5},
									{2, 3, 4, 5, 6}
								 };
	printf("%d\n", adjacent(input)==12);
	printf("%d\n", iterative(input));
	// printf("%d\n", adjacent(input)==);
	return 0; 
}