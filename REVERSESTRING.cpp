/*REVERSESTRING*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 

string reverseString(string A){
	stack<char> s;
	string answer ="";
	for (int i = 0; i < A.size(); ++i){
		s.push(A[i]);
	}
	for (int i = 0; i < A.size(); ++i)
	{
		answer = answer + s.top();
		s.pop();
	}
	return answer;
}

int main(int argc, char const *argv[]){
	string s1 = "[(])";
	string s2 = "()[]{}";
	// idea: last unclosed, first closed 
	// printf("%d, expected: 0",isValid(s1));
	// printf("%d, expected: 1",isValid(s2));
	printf("%s\n", reverseString(s2).c_str());
}