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
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++) 


bool isValid(vi A, int current_pos){
	for (int i = 0; i < current_pos; ++i){
		if (A[i]==A[current_pos] || abs(A[i]-A[current_pos])==(current_pos - i)){
			return false;
		}
	}
	return true;
}

void toString(vvi &answer, vi A){
	tr(A, it){
		printf("%d\n", *it);
	}
}

void nqueens(vi A, vvi &answer, int current){
	if(current==A.size())
		toString(answer, A);
	else{
		for (int i = 0; i < A.size(); ++i){
			A[current] = i;
			if(isValid(A, current))
				nqueens(A, answer, current+1);
		}
	}
}

vector<vector<string> > solveNQueens(int A) {

}


int main(int argc, char const *argv[]){
	vi input = {1,2,3};
	// vvi answer  = permute(input);
	// tr(answer, it){
	// 	tr((*it), itt){
	// 		printf("%d,", *itt);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}