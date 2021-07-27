/*Noble Integer
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.*/
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
#define all(c) (c).begin(),(c).end() 
#define max(x, y) ((x > y) ? x : y);

class Solution {
public:
	vector<int> wave(vector<int> &A) {
		int n = A.size();
		vector<int> answer;
		sort(A.begin(), A.end());
		int i;
		for (i = 1; i < n; i+=2){
			answer.push_back(A.at(i));
			answer.push_back(A.at(i-1));
		}
		if (n % 2 !=0){
			answer.push_back(A.at(i-1));
		}
		return answer;
	}
};

int main(int argc, char const *argv[])
{
	vi x = {-4, 7, 5, 3, 5, -4, 2, -1, -9, -8, -3, 0, 9, -7, -4, -10, -4, 2, 6, 1, -2, -3, -1, -8, 0, -8, -7, -3, 5, -1, -8, -8, 8, -1, -3, 3, 6, 1, -8, -1, 3, -9, 9, -6, 7, 8, -6, 5, 0, 3, -4, 1, -10, 6, 3, -8, 0, 6, -9, -5, -5, -6, -3, 6, -5, -4, -1, 3, 7, -6, 5, -8, -5, 4, -3, 4, -6, -7, 0, -3, -2, 6, 8, -2, -6, -7, 1, 4, 9, 2, -10, 6, -2, 9, 2, -4, -4, 4, 9, 5, 0, 4, 8, -3, -9, 7, -8, 7, 2, 2, 6, -9, -10, -4, -9, -5, -1, -6, 9, -10, -1, 1, 7, 7, 1, -9, 5, -1, -3, -3, 6, 7, 3, -4, -5, -4, -7, 9, -6, -2, 1, 2, -1, -7, 9, 0, -2, -2, 5, -10, -1, 6, -7, 8, -5, -4, 1, -9, 5, 9, -2, -6, -2, -9, 0, 3, -10, 4, -6, -6, 4, -3, 6, -7, 1, -3, -5, 9, 6, 2, 1, 7, -2, 5};
	vi y = {1, 2, 3, 4, 5}; //[2, 1, 4, 3]
	Solution S;
	vi answer = S.wave(y);
	for (std::vector<int>::iterator i = answer.begin(); i != answer.end(); ++i)
	{
		printf("%d\n", *i);
	}
	// printf("%d\n", S.solve(x));
	// printf("%d\n", S.solve(y));
	return 0;
}

// class Solution {
// public:
//     int longestLine(vector<vector<int>>& M) {
//         int RR = M.size();
//         // if(rows_number == 0) return 0;
//         int CC = M[0].size();
//         // if(cols_number == 0) return 0;
//  		vector<vector<bool> > matrix(RR, std::vector<bool>(CC, false));
//         int answer = 0;
//         return answer;
//     }
// };

// int main(int argc, char const *argv[]){
// 	vvi x = {{0,1,1,0},
//  			{0,1,1,0},
//  			{0,0,0,1}};
	
// 	Solution S;
	
// 	printf("Final answer: %d\n", S.longestLine(x));
// 	return 0;
// }