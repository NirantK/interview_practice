/*PERMUTATIONS*/
/*https://leetcode.com/problems/permutations/*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define pb push_back 
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 

void realPermute(vi &num, int k, vvi &result){
	if(k==num.size()){
		result.pb(num);
	}else{
		for (int i = k; i < num.size(); ++i){
			swap(num[i], num[k]);
			realPermute(num, k+1, result);
			swap(num[i], num[k]);
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vvi answer;
	realPermute(nums, 0, answer);
	return answer;
}


int main(int argc, char const *argv[]){
	vi input = {1,2,3};
	vvi answer  = permute(input);
	tr(answer, it){
		tr((*it), itt){
			printf("%d,", *itt);
		}
		printf("\n");
	}
	return 0;
}