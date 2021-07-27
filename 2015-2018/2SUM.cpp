#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define pb push_back 
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++) 

/*Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2*/

// https://www.interviewbit.com/courses/programming/topics/hashing/problems/2sum/	

vector<int> twoSum(const vector<int> &A, int B) {
    int target;
    unordered_map <int, int> map;
    for (int i = 0; i < A.size(); ++i){
    	target = B - A[i];
    	printf("%d\n", target);
    	if(map.find(target)!=map.end()){
    		// printf("%d, %d\n", map[target], i);
    		vi answer = {map[target]+1, i+1};
    		return answer;
    	}
    	else if(map.find(A[i])==map.end())
    		map[A[i]] = i;
    }
    vi answer;
    return answer;
}



int main(int argc, char const *argv[]){
	vi input = {1,-2,2,4,-4}; 
	input = {2,7,11,15};
	input = {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
	int sum = -3;
	// input = {1,2,-3,3};
	// input = {-8, 8, -1, -16, -28, -27, 15, -14, 14, -27, -5, -6, -25, -11, 28, 29, -3, -25, 17, -25, 4, -20, 2, 1, -17, -10, -25 };
	// input = {-1, 1, 1, -1, -1, 1, 1, -1};
	// input = {10, 13, -1, 8, 29, 1, 24, 8, 21, 20, 21, -23, -21, 0 };
	vi answer = twoSum(input, sum);
	tr(answer, it){
		printf("%d,", (*it));
	}
	return 0;
}