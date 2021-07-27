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
	// Input : X and Y co-ordinates of the points in order. 
	// Each point is represented by (X[i], Y[i])
	int solve(vector<int> &A) {
		int n = A.size();
		sort(A.begin(), A.end());
		for (int i = 0; i < n; ++i){
			int greater_than_p = n - i - 1;
			int p = A[i];
			if(p == greater_than_p){
				// printf("p: %d\n", p);
				if(i < n-1 && p != A.at(i+1)){
					// printf("p: %d\n", p);
					return 1;
				}
				if(i == n-1){
					return 1;
				}
			}
		}
		return -1;
	}
};

int main(int argc, char const *argv[])
{
	vi x = {-4, 7, 5, 3, 5, -4, 2, -1, -9, -8, -3, 0, 9, -7, -4, -10, -4, 2, 6, 1, -2, -3, -1, -8, 0, -8, -7, -3, 5, -1, -8, -8, 8, -1, -3, 3, 6, 1, -8, -1, 3, -9, 9, -6, 7, 8, -6, 5, 0, 3, -4, 1, -10, 6, 3, -8, 0, 6, -9, -5, -5, -6, -3, 6, -5, -4, -1, 3, 7, -6, 5, -8, -5, 4, -3, 4, -6, -7, 0, -3, -2, 6, 8, -2, -6, -7, 1, 4, 9, 2, -10, 6, -2, 9, 2, -4, -4, 4, 9, 5, 0, 4, 8, -3, -9, 7, -8, 7, 2, 2, 6, -9, -10, -4, -9, -5, -1, -6, 9, -10, -1, 1, 7, 7, 1, -9, 5, -1, -3, -3, 6, 7, 3, -4, -5, -4, -7, 9, -6, -2, 1, 2, -1, -7, 9, 0, -2, -2, 5, -10, -1, 6, -7, 8, -5, -4, 1, -9, 5, 9, -2, -6, -2, -9, 0, 3, -10, 4, -6, -6, 4, -3, 6, -7, 1, -3, -5, 9, 6, 2, 1, 7, -2, 5};
	vi y = {-4, -2, 0, -1, -6}; //1
	Solution S;
	int answer = S.solve(x);
	printf("%d\n", S.solve(x));
	printf("%d\n", S.solve(y));
	return 0;
}