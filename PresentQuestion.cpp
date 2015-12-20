/*FRACTION*/
// https://www.interviewbit.com/courses/programming/topics/hashing/problems/colorful/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define pb push_back 
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++) 

size_t stringCount(const std::string& referenceString,
                   const std::string& subString) {

  const size_t step = subString.size();

  size_t count(0);
  size_t pos(0) ;

  while( (pos=referenceString.find(subString, pos)) !=std::string::npos) {
    pos +=step;
    ++count ;
  }

  return count;

}

string fractionToDecimal(int numerator, int denominator) {
	// string answer = "";
	// double fraction = ((double)numerator)/denominator;
	// map <string, int> hashmap; 
	// int temp = (int) fraction;
	// // printf("Int part is %d\n", temp);
	// answer += to_string(temp);
	// // answer += ".";
	// if(((double)temp-fraction)==0.0)
	// 	return to_string(temp);
	// string input = to_string(fraction - temp);	
	// printf("%s\n", input.c_str());
	// for (int i = 2; i < input.size(); ++i){
	// 	for(int j = i; j < input.size(); ++j){
	// 		string substring = input.substr(i, j);
	// 		// printf("substring: %s\n", substring.c_str());
	// 		if(hashmap.find(substring)==hashmap.end())
	// 			hashmap.insert({substring, 1});
	// 		else
	// 		hashmap[substring] += 1;	
	// 	}
	// }
	// map <int, string> counts;
	// for(auto it = hashmap.begin(); it != hashmap.end(); ++it){
	//     // std::cout << it->first << " " << it->second << "\n";
	//     int count = stringCount(input, it->first);
	//     printf("%s : %d\n", it->first.c_str(), count);
	//     // if(it->second >= 2)
	//     	// answer += it->first;
	// }

	// return answer;

	if (numerator == 0 || denominator == 0)	{
		return "0";
	}
	bool positive = true;
	if (numerator * denominator < 0)
		positive = false;
	numerator = abs(numerator);
	denominator = abs(denominator);
	vs result;
	int maxlen = 200;
	// vs mod;
	int l = -1;
	map <string, int> hashmap;
	while(hashmap.size() < maxlen){
		result.push_back(to_string(abs(numerator / denominator)));
		long modulus = numerator % denominator;
		if(modulus==0)
			break;
		if(hashmap.find(to_string(modulus))!=hashmap.end()){
			l = hashmap[to_string(modulus)];
			printf("%d\n", l);
			break;
		}
		else{
			hashmap[to_string(modulus)] = 1;
			numerator = modulus * 10;
		}
	}
	string answer;
	// if(1==result.size())
	// 	answer = result[0];
	// else{
	// 	answer = result[0] + ".";
	// 	if(-1 == l)
	// 		answer += 
	// }
	// string answer;
	return answer;

}

int main(int argc, char const *argv[]){
	// printf("%s\n", fractionToDecimal(5, 10).c_str());
	// printf("%s\n", fractionToDecimal(10, 5).c_str());
	// printf("%s\n", fractionToDecimal( 4, 3).c_str());
	// printf("Returned: %s \t Expected: 4.(54)\n", fractionToDecimal(50, 11).c_str());
	printf("%s\n", fractionToDecimal(500, 99).c_str());
	// printf("%s\n", fractionToDecimal(69069, 200000).c_str());
	return 0;
}