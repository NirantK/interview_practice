/*SIMPLIFYPATH*/
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

#include <limits.h>
string simplifyPath(string path){
	stack<string> dirs;
	string temp ="";
	int flag =0;
	for (int i=0;i<path.size();++i){
		if (path[i]=='/')
		{
			if(dirs.empty())
				dirs.push(temp);
			else if(!dirs.empty() && dirs.top()!=temp)
				dirs.push(temp);
		}
		else
			temp += path[i];
		}
	
	string answer = "";
	for (int i = 0; i < dirs.size(); ++i){
		// if (dirs.top()=="."){
		// 	answer += dirs.top();
		// 	break;		
		// }
		printf("%s\n", dirs.top().c_str());
		dirs.pop();
	}
	return answer;
}
int main(int argc, char const *argv[]){
	string s = "/home//";
	printf("\n%s",simplifyPath(s).c_str());
	printf("\n%s",simplifyPath("/a/./b/../../c/").c_str());
	return 0;
}