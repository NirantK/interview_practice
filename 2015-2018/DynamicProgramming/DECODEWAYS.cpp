// DECODEWAYS
// Amazon, Facebook question basic DP. Could not solve this on my own
// Clearing my solution completely
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
// typedef vector<string> vs;
// typedef vector<vs> vvs;
#define pb push_back
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)

bool isValid(char ch) {
	return (isdigit(ch) && ch > '0');
}

int solution[100001];
int ways(string &s, int startIndex) {
	// This is the magnificent function worth taking note
	if (startIndex == s.length()) return 1;
	if (!isValid(s[startIndex])) return 0;
	
	// memoize
	if (solution[startIndex] != -1) return solution[startIndex];
	
	int answer = 0;
	// 1 digit
	answer += ways(s, startIndex + 1);
	// 2 digit
	if (startIndex < s.length() - 1 && isdigit(s[startIndex + 1]) && ((s[startIndex] - '0') * 10 + s[startIndex + 1] - '0') <= 26) {
		answer += ways(s, startIndex + 2);
	}

	return solution[startIndex] = answer;
}
int numDecodings(string s) {
	memset(solution, -1, s.length() * sizeof(int));
	if (s.length() == 0) return 0;
	return ways(s, 0);
}



int main(int argc, char const *argv[]){
	vi values = {1,2,3,4,5};
	int x = 15;
	// printf("%d ", minCoinChange(x, values));     
	printf("%d ", numDecodings("10")==1);
	printf("%d ", numDecodings("12")==2);
	printf("%d ", numDecodings("0")==0);
	printf("%d ", numDecodings("20")==1);
	printf("%d ", numDecodings("26")==2);
	printf("%d ", numDecodings("27")==1);
	printf("%d ", numDecodings("2121")==5);
	assert(numDecodings("875361268549483279131")==6);
	printf("%d ", numDecodings("875361268549483279131")==6);


	return 0; 
}

/*int minCoinChange(int x, vi &values){
	if(x==0 ^ values.size()<=0) return 0;
	vi table(x+1, INT_MAX);
	table[0] = 0;
	for (int i = 1; i <= x; ++i){
		for (int j = 0; j < values.size(); ++j){
			if(values[j] <= i){
				int temp = table[i-values[j]];
				if((temp + 1) < table[i])
					table[i] = temp + 1;
			}
		}
	}
	return table[x];
}*/