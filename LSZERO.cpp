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

/*Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. */

vector<int> lszero(vector<int> &A) {
	vi answer;
	int sum = 0;
	vi temp(A.size());
	// unordered_map <int, int> map;
	for (int i = 0; i < A.size(); ++i){
		sum += A[i];
		temp[i] = sum;
	}
	// tr(temp, it){
	// 	printf("%d, ", (*it));
	// }
	unordered_map <int, int> map;
	int maxlen = 0;
	for (int i = 0; i < temp.size(); ++i)
	{
		if((temp[i]==0) && (i >= maxlen)){
			answer.clear();
			printf("maxlen:%d, i:%d\n", maxlen, i);
			maxlen = i+1;
			for(int k = 0; k <= i; ++k)
				answer.pb(A[k]);
		}

		if(map.find(temp[i])!=map.end()){
			int diff = i - map[temp[i]];
			printf("maxlen:%d, diff:%d, i:%d, old_i:%d\n", maxlen, diff, i, map[temp[i]]);
			if(diff > maxlen){
				maxlen = diff;
				answer.clear();
				for(int k = map[temp[i]]+1; k <=i ; ++k)
						answer.pb(A[k]);
			}
		}else{
			map[temp[i]]= i;
			printf("map[%d] = %d\n", temp[i], map[temp[i]]);
		}

		// for (int j = i+1; j < temp.size(); ++j)
		// {
		// 	if(temp[i]==temp[j]){
		// 		if((j-i) > maxlen){
		// 			printf("maxlen:%d, i:%d, j:%d\n", maxlen, i, j);
		// 			maxlen = j-i;
		// 			answer.clear();
		// 			for(int k = i+1; k <= j; ++k)
		// 				answer.pb(A[k]);
		// 		}
		// 	}
		// }
	}
	return answer;
}

/*INTERVIEWBIT SOLUTION*/
//Same logic, more elegant and simpler to understand
vector<int> lszero(vector<int> &sequence) {
        
        int N = sequence.size();
        vector<int> sum;
        if(N == 0)
                return sum; // empty vector

        sum.push_back(sequence[0]);

        for(int i = 1; i < N; ++i) {
            sum.push_back(sequence[i] + sum[i - 1]);
        }
        
        int start = 0;
        int end = 0;
        map<int, int> hash;
        for(int i = 0; i < N; ++i) {
            if(sum[i] == 0) {
                int temp_start = 0;
                int temp_end = i + 1;
                if(temp_end - temp_start >= end - start) {
                    start = temp_start;
                    end = temp_end;
                } 
            } else {
                if(hash.find(sum[i]) != hash.end()) {
                    int temp_start = hash[sum[i]] + 1;
                    int temp_end = i + 1;
                    if(temp_end - temp_start > end - start) {
                        start = temp_start;
                        end = temp_end;                  
                    } else if(temp_end - temp_start == end - start && temp_start < start) {
                        start = temp_start;
                        end = temp_end;
                    }
                } else {
                    hash[sum[i]] = i;
                }
            }
        }

        vector<int> ans;

        for(int i = start; i < end; ++i) {
            ans.push_back(sequence[i]);
        }

        return ans;
    }


int main(int argc, char const *argv[]){
	vi input = {1,-2,2,4,-4};
	input = {1,2,-3,3};
	input = {-8, 8, -1, -16, -28, -27, 15, -14, 14, -27, -5, -6, -25, -11, 28, 29, -3, -25, 17, -25, 4, -20, 2, 1, -17, -10, -25 };
	input = {-1, 1, 1, -1, -1, 1, 1, -1};
	input = {10, 13, -1, 8, 29, 1, 24, 8, 21, 20, 21, -23, -21, 0 };
	vi answer = lszero(input);
	tr(answer, it){
		printf("%d,", (*it));
	}
	return 0;
}