#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*INTERVIEWBIT SOLUTION

class Solution {
    public:
        int sqrt(int x) {
            if (x == 0) return 0;
            int start = 1, end = x, ans;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (mid <= x / mid) {
                    start = mid + 1;
                    ans = mid;
                } else {
                    end = mid - 1;
                }
            }
            return ans;
        }
};*/


int sqrt(int A){
	int low = 0;
	int high = A;
	int mid;
	if (A == 1){
		return 1;
	}
	while((high-low) > 1){
		long mid = low+(high-low)/2;
		// printf("Mid: %d\n", mid);
		long square = (long) mid * mid;
		if(square == A){
			return mid;
		}
		else if(square < A ){
			low = mid;
			// printf("Low: %d\n", low);
		}else{
			high = mid;
			// printf("High: %d\n", high);
		}
	}
	return low;
}

int main(void) {
	// printf("%d\n", sqrt(930675566)==30506);
	// printf("%d\n", sqrt(4)==2);
	// printf("%d\n", sqrt(1)==1);
	// printf("%d\n", sqrt(0)==0);
}