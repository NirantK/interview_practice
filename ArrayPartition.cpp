/*Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4.
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].

from LeetCode Contest 29*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
// #include "macros.h"
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define pb push_back 
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++) 
#define all(c) (c).begin(),(c).end() 
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(all(nums));
        int sum  = 0;
        for (int i = 0; i < nums.size(); i+=2)
        {
        	sum += nums[i];
        }
        return sum;
    }
};
int main(int argc, char const *argv[]){
	vi x = {1, 4, 3, 2};
	Solution S;
	printf("Final Answer: %d\n", S.arrayPairSum(x));
	return 0;
}