// Find out the maximum sub-array of non negative numbers from an array.
// The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

// Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

// Example:

// A : [1, 2, 5, -7, 2, 3]
// The two sub-arrays are [1, 2, 5] [2, 3].
// The answer is [1, 2, 5] as its sum is larger than [2, 3]
// NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
// NOTE 2: If there is still a tie, then return the segment with minimum starting index

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
// return elements of max ranges
class Solution {
public:
	vector<int> maxset(vector<int> &A) {
		std::vector<int> newArray;
		std::vector<int> maxArray;
		long maxSum = 0;
		long newSum = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			if(A[i] >= 0){
				newSum += A[i];
				newArray.push_back(A[i]);
			}else{
				newSum = 0;
				newArray.clear();
			}
			if(maxSum < newSum){
				maxSum = newSum;
				maxArray = newArray;
			}
			if(maxSum == newSum && newArray.size() > maxArray.size()){
				maxArray = newArray;
				maxSum = newSum;
			}
		}
		return maxArray;
	}
};

int main(int argc, char const *argv[])
{
	vi x = {1, 2, 5, -1, 3, 2, 1, 2};
	Solution S;
	vi answer = S.maxset(x);
	for (std::vector<int>::iterator i = answer.begin(); i != answer.end(); ++i){
		printf("%d\n", *i);
	}
	return 0;
}