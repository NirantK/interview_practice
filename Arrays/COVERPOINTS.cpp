/*You are in an infinite 2D grid where you can move in any of the 8 directions :
 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Example :
Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).

This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.
*/
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
	int coverPoints(vector<int> &X, vector<int> &Y) {
		if(X.size() == 0) return 0;
		if(Y.size() == 0) return 0;
		int startx = X[0];
		int starty = Y[0];
		int steps = 0;

		for (int i = 1; i < X.size(); ++i){
			int x = abs(X[i] - startx);
			int y = abs(Y[i] - starty);

			startx = X[i];
			starty = Y[i];

			steps += max(x, y);
		}
		return steps;
	}
};

int main(int argc, char const *argv[])
{
	vi X = {0, 1, 2};
	vi Y = {0, 1, 5};
	Solution S;
	int answer = S.coverPoints(X, Y);
	printf("%d\n", answer);
	return 0;
}