/*SUBSET*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 

// string getBinary(int i, int len){
// 	// len is the length of binary string needed
// 	// i is the number which needs to be converted to binary
// 	string binaryofI = "";
// 	while(i>0){
// 		// printf("%c, ", char(i%2 + '0'));
// 		// i = i/2;
// 		binaryofI += char(i%2 + '0');
// 		i = i/2;
// 	}
// 	for (int i = 0; i < len-binaryofI.size(); ++i){
// 		binaryofI += '0';
// 	}
// 	// printf("%s\n", binaryofI.c_str()); 
// 	return binaryofI;
// }
// vector<vector<int>> subsets(vector<int>& nums) {
// 	sort(nums.begin(), nums.end());
// 	vvi res;
// 	int n = nums.size();
// 	vector<string> binaryConverts;
// 	for (int i = 0; i < pow(2, n); ++i){
// 		binaryConverts.push_back(getBinary(i, n));
// 	}
// 	// sort(binaryConverts.begin(), binaryConverts.end());
// 	// tr(binaryConverts, it){
// 	// 	printf("%s\n", (*it).c_str());
// 	// }
// 	for (int i = 0; i < binaryConverts.size(); ++i){
// 		vi ss;
// 		for (int j = 0; j < n; ++j){
// 			if(binaryConverts[i][j]=='1'){
// 				ss.push_back(nums[j]);
// 			}
// 		}
// 		res.push_back(ss);
// 	}
// 	sort(res.begin(), res.end());
// 	return res;
// }

typedef vector<int> vi; 
typedef vector<vi> vvi;
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 

void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
    if (index >= S.size()) {
        result.push_back(current);
        return;
    }
    // Ignore the current index.
    generateSubsets(S, index + 1, current, result);

    // Include the current index. 
    current.push_back(S[index]);
    generateSubsets(S, index + 1, current, result);
    current.pop_back();
}

vector<vector<int>> subsets(vector<int>& S) {
    vector<vector<int> > result; 
    vector<int> current;
    sort(S.begin(), S.end());
    generateSubsets(S, 0, current, result);
    sort(result.begin(), result.end());
    return result;
}


int main(int argc, char const *argv[]){
	vi input = {2, 20, 6, 16, 19, 13 };
	vvi answer = subsets(input);
	tr(answer, it){
		tr((*it), i){printf("%d,", *i);}
		printf("\n");
	}
	return 0;
}