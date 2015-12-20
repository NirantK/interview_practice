/*LONGESTPALIN*/
/*fucking memorise the problem and solution*/
/*http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-i.html*/
/*http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html*/

#include <vector>
#include <string>
// #include <sstream>
#include <algorithm>
using namespace std;
typedef vector<unsigned long long> vi; 
typedef vector<vi> vvi; 
// typedef pair<int,int> ii; 
#define all(c) (c).begin(),(c).end() 
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}

string longestPalindrome(string s){
	int n = s.length();
	if (n == 0) return "";
    string longest = s.substr(0, 1);  // a single char itself is a palindrome
    for (int i = 0; i < n-1; i++) {
	string p1 = expandAroundCenter(s, i, i);
	if (p1.length() > longest.length())
		longest = p1;
 
 	string p2 = expandAroundCenter(s, i, i+1);
	if (p2.length() > longest.length())
	  longest = p2;
  }
  return longest;
}
int main(int argc, char const *argv[]){
	// printf("\nOutput:%d Expected:-1",compareVersion("444444444444444444444444", "4444444444444444444444444"));
	printf("%s\n", longestPalindrome("").c_str());
	printf("%s\n", longestPalindrome("a").c_str());
	printf("%s\n", longestPalindrome("ab").c_str());
	printf("%s\n", longestPalindrome("abracadabra").c_str());
	printf("%s\n", longestPalindrome("aba").c_str());

	return 0;
}