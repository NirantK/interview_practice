/*int to roman*/
/*https://www.interviewbit.com/courses/programming/topics/strings/problems/int2roman/*/
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
// #include <pair>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
// typedef pair<int,int> ii; 
#define all(c) (c).begin(),(c).end() 
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

string intToRoman(int A) {
	int num = A;
	vector<int> integer = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	vector<string> roman = {"M", "CM", "D","CD","C", "XC","L","XL", "X", "IX","V","IV", "I"};

	// if (num<1)
	// return null;

	string str="";
	for(int i = 0; i < integer.size(); i ++){
		int q = num/integer[i];
		while(q>0){
			str=str+roman[i];
			q--;
		}
		num = num % integer[i];
	}

return str;
}

string intToRoman_officialInterviewbit(int num){
        // 1000, 2000, 3000
        string M[] = {"", "M", "MM", "MMM"};
        // 100, 200, 300, .. 900
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        // 10, 20, ... 90
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        // 1, 2, ... 9
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}

int main(int argc, char const *argv[]){
	printf("\nOutput:%s Expected:M",intToRoman(1000).c_str());
	printf("\nOutput:%s Expected:XV",intToRoman(15).c_str());
	printf("\nOutput:%s Expected:XIV",intToRoman(14).c_str());

	return 0;
}