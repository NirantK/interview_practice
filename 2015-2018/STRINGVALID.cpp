/*STRINGISVALID*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 

// class Solution {
//     public:
//         bool isValid(string s) {
//             stack<char> st;
//             map<char, char> matchingBracket; 
//             matchingBracket['{'] = '}';
//             matchingBracket['['] = ']';
//             matchingBracket['('] = ')';
//             for (int i = 0; i < s.length(); i++) {
//                 if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
//                     st.push(s[i]);
//                 } else if (st.empty() || matchingBracket[st.top()] != s[i]) {
//                     return false;
//                 } else {
//                     st.pop();
//                 }
//             }
//             return st.empty();
//         }
// };
int isValid(string A) {
	stack<char> s;
	for (int i = 0; i < A.length(); ++i){
		char x = A[i];
		if('('==x || '['==x || '{'==x){
			s.push(x);
		}
		else{
			if(s.empty()) return 0;
			char t = s.top();
			if((')'==x) && (t!='(')) return false;
			else if((']'==x) && ('['!=t)) return false;
			else if(('}'==x) && ('{'!=t)) return false;
			s.pop();
		}
	}
	return s.empty();		
}


int main(int argc, char const *argv[]){
	string s1 = "[(])";
	string s2 = "()[]{}";
	// idea: last unclosed, first closed 
	// printf("%d, expected: 0",isValid(s1));
	// printf("%d, expected: 1",isValid(s2));
	printf("%s\n", reverseString(s2).c_str());
}