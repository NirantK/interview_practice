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
/*Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.*/

int isValidString(const string &input){
	unordered_map <char, bool> map;
	for (int i = 0; i < input.size(); ++i){
		if(input[i]=='.')
			continue;
		else{
			if(map.find(input[i])!=map.end())
				return 0;
			else
				map[input[i]]==true;
		}
	}
	return 1;
}

int isValidSudoku(const vector<string> &A) {
	//check all rows, each string in the vector is a row
	for (int i = 0; i < A.size(); ++i){
		if(!isValidString(A[i]))
			return 0;
	}
	//check all columns
	for (int i = 0; i < A[0].size(); ++i){
		string column = "";
		for (int j = 0; j < A[0].size(); ++j){
			column += A[j][i];
		}
		// printf("%s -- ", column.c_str());
		if(!isValidString(column))
			return 0;
	}
	//check all grids
	for(int k =0; k<9; k+=3){
		for(int l=0; l<9; l+=3){
			string grid = "";
			for (int i = k; i < k+3; ++i){
				for (int j = l; j < l+3; ++j){
					grid += A[i][j];
					// printf("%c,", A[i][j]);
				}
			}
			// printf("%s\n", grid.c_str());
			if(!isValidString(grid))
				return 0;
		}
	}
	return 1;
}


int main(int argc, char const *argv[]){
	vs input = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"}; 
	// int answer = 
	printf("%d\n", isValidSudoku(input));
	// tr(answer, it){
	// 	printf("%d,", (*it));
	// }
	return 0;
}