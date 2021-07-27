#include <cstdio>
#include <climits>
#include <iostream>
#include <cmath>
using namespace std;

bool isPower(int A){
	if(A ==	0)
		return false;
	if(A == 1)
		return true;
	for(int i=2; i<33; i++){
		int maximum_P = pow(INT_MAX, 1.0/i);
		// printf("%d\n", maximum_P);
		for(int j=2; j<=maximum_P+2; j++){
			// printf("%d ** %d = %f\n", i, j, pow(i,j));
			if(A==pow(j, i)){
				return true;
			}
		}
		// printf("%d\n", i);
	}
	return false;
}
int main(void) {
	// cout << INT_MAX << endl;
	// int input;
	// cin >> input;
	if (isPower(1024000000)){
		cout << "True";
	}
	else{
		cout << "False";
	}
}