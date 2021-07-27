/*LENGTHLAST*/
#include <vector>
#include <string>
#include <sstream>
// using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
// typedef pair<int,int> ii; 
#define all(c) (c).begin(),(c).end() 
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

// int lengthOfLastWord(const string &A){
// 	int position = 0;
// 	int sz = A.length();
// 	if(sz==0)
// 		return 0;
// 	for(int i= sz - 1; i >= 0; --i){
// 		if (A[i]!=' '){
// 		// look for first non-space character from right, that is length of last word
// 			position++;
// 		}
// 		else if(position > 0){
// 			return position;
// 		}
// 	}
// 	// if(position>0)
// 		// return position;
// 	// else
// 	return position;
// }

/*Interviewbit Solution*/
int lengthOfLastWord(const string &s) {
    int len = 0;
    
    for (auto traversalCharacter:s){
    	// printf("%c\n", i);
    	if(traversalCharacter != ' '){
    		len++;
    		printf("\n%d, %c", len, traversalCharacter);
    		continue;
    	}
    	// len;
    	else if(traversalCharacter && traversalCharacter!= ' ')
    		len = 0;
    	// else
    	// 	return len;
    }
    return len;
    // while (*s) {
    //     if (*s != ' ') {
    //         len++;
    //         s++;
    //         continue;
    //     }
    //     s++;
    //     if (*s && *s != ' ') len = 0;
    // }
    // return len;
}

int main(int argc, char const *argv[]){
	printf("\nOutput:%d Expected:4",lengthOfLastWord("XXIV"));
	printf("\nOutput:%d Expected:5",lengthOfLastWord("Hellow World"));
	printf("\nOutput:%d Expected:5",lengthOfLastWord("World    "));
	printf("\nOutput:%d Expected:0",lengthOfLastWord(""));

	return 0;
}