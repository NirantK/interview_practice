/*NUM1BITS*/
#include <cstdio>
using namespace std;
int NUM1BITS(usigned int x){
	// this solution does not work for signed integers
	unsigned int count = 0;
	while(x!=0){
		x =  x & (x-1);
		// this clears the lowest set bit
		// or in simpler words, sets the least significant 1 to 0
		// uncomment the next line to see how the number changes
		// printf("%d\n", x);
		++count;
	}
	return count;
}

int main(int argc, char const *argv[]){
	printf("%d\n", NUM1BITS(11));
	return 0;
}