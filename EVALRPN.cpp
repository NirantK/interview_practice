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

int evalRPN(vector<string> &A) {
	stack<int> s;
	for (int i = 0; i < A.size(); ++i){
		if("+" == A[i]|| "-"==A[i] || "*" == A[i] || "/" == A[i]){
			if(!s.empty()){
				int v1 = s.top(); s.pop();
				int v2 = s.top(); s.pop();
				char op = A[i][0];
				if('+'==op)
					s.push(v1+v2);
				else if('-' == op)
					s.push(v2 - v1);
				else if('*' == op)
					s.push(v2 * v1);
				else if('/' == op)
					s.push(v2 / v1);
			}
		}else{
			s.push(atoi(A[i].c_str()));
		}
	}
	return s.top();
}	




int main(int argc, char const *argv[]){
	vector<string> s1 = {"2","1", "+", "3", "*"};
	vector<string> s2 = {"4", "13", "5", "/", "+"};
	// string s2 = "()[]{}";
	// idea: last unclosed, first closed 
	// printf("%d, expected: 0",isValid(s1));
	// printf("%d, expected: 1",isValid(s2));
	// printf("%s\n", reverseString(s2).c_str());
	printf("%d", evalRPN(s1)==9);
	printf("%d", evalRPN(s2)==6);
}