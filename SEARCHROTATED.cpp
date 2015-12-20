/*SEARCH ROTATED*/
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
// typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

int search(const vector<int> &A, int B){
	// vi &A = A;
	// int target = B;
	int L = 0, R = A.size()-1;
	while(L<=R){
		int M = L + (R-L)/2;
		if(A[M]==B){
			return M;
		}else if(A[L] <= A[M]){
			if(B >= A[L] && B < A[M])
				R = M - 1;
			else
				L = M + 1;
		}else{
			if(A[R] >= B && A[M] < B)
				L = M + 1;
			else
				R = M - 1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[]){
	vi A = { 19, 20, 21, 22, 28, 29, 32, 36, 39, 40, 41, 42, 43, 45, 48, 49, 51, 54, 55, 56, 58, 60, 61, 62, 65, 67, 69, 71, 72, 74, 75, 78, 81, 84, 85, 87, 89, 92, 94, 95, 96, 97, 98, 99, 100, 105, 107, 108, 109, 110, 112, 113, 115, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 128, 130, 131, 133, 134, 135, 136, 137, 138, 139, 141, 142, 144, 146, 147, 148, 149, 150, 153, 155, 157, 159, 161, 163, 164, 169, 170, 175, 176, 179, 180, 185, 187, 188, 189, 192, 196, 199, 201, 203, 205, 3, 7, 9, 10, 12, 13, 17 };
	// nextPermutation(A);
	// tr(A, it){
	// 	printf("%d", *it);
	// }
	printf("\n%d", search(A, 6));
	// vi B = {3,2,1};
	// nextPermutation(B);
	// tr(B, it){
		// printf("%d", *it);
	// }

	return 0;
}