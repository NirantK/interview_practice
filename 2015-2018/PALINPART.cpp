/*PALINPART*/
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

int isPalindrome(string &input, int start, int end){
	while(start<end){
		// printf("%s\n", input.c_str());
		// printf("%c %c\n", input[start], input[end]);
		if (input[start]==input[end]){
			++start;
			--end;
		}
		else
			return 0;
	}
	return 1;
}

void createStringPartitions(string &input, int index, vs &temp, vvs &answer){
	if(index >= input.size()){
		answer.pb(temp);
	}
	else{
		for (int i = index; i < input.size(); ++i){
			if(isPalindrome(input, index, i)){
				temp.pb(input.substr(index, i-index+1));
				createStringPartitions(input, i+1, temp, answer);
				temp.pop_back();
			}
		}
	}
}

vector<vector<string>> partition(string s) {
	vvs answer;
	vs temp;
	// temp.push_back(s);
	// answer.pb(temp);
	createStringPartitions(s, 0, temp, answer);
	// printf("%s\n", answer[0][0].c_str());
	return answer;
}

int main(int argc, char const *argv[]){
	string test = "aab";
	vvs answer = partition(test);
	tr(answer, it){
		tr((*it), i){
			printf("%s, ", (*i).c_str());
		}
		printf("\n");
	}
	// printf("%d\n", isPalindrome(test, 0, test.size()-1));
	return 0;
}