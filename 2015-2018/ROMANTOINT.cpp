/*ROMANTOINT*/
/*https://www.interviewbit.com/courses/programming/topics/strings/problems/roman2int/*/
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
// typedef pair<int,int> ii; 
#define all(c) (c).begin(),(c).end() 
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
int stringCount(const std::string& referenceString,
                   const std::string& subString) {

  const size_t step = subString.size();

  int count(0);
  int pos(0) ;

  while( (pos=referenceString.find(subString, pos)) !=std::string::npos) {
    pos +=step;
    // pos++;	
    ++count ;
  }

  return count;

}

int romantoint(string A){
	vector<int> integer = {1000, -200, 500, -200, 100, -20, 50, -20, 10, -2, 5, -2, 1};
	vector<string> roman = {"M", "CM", "D","CD","C", "XC","L","XL", "X", "IX","V","IV", "I"};
	int answer = 0;
	for (int i =0; i< roman.size(); i++){
		answer  = answer + integer[i]*stringCount(A, roman[i]);
		// printf("%d %d\n", integer[i], stringCount(A, roman[i]));
	}
	return answer;
}


/*************************************************************************/
/*interviewbit solution*/
/*This exactly mimics the way we think of roman numerals instead of making it 
complicated by using a dictionary in the way I have*/
int romanToInt(string s) {
        int num = 0;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            // Does lesser value precede higher value ? 
            if (i < (size - 1) && romanCharToInt(s[i]) < romanCharToInt(s[i + 1])) {
                num -= romanCharToInt(s[i]);
            } else {
                num += romanCharToInt(s[i]);
            }
        }
        return num;
    }

    int romanCharToInt(char c) {
        switch (c) {
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
            default:    return 0;
        }
    }

int main(int argc, char const *argv[]){
	printf("\nOutput:%d Expected:24",romantoint("XXIV"));
	printf("\nOutput:%d Expected:29",romantoint("XXVIV"));
	// printf("\nOutput:%d Expected:XV",intToRoman(15).c_str());
	// printf("\nOutput:%d Expected:XIV",intToRoman(14).c_str());

	return 0;
}