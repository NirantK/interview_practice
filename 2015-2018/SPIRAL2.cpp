/*SPIRAL1*/
#include <vector>
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

void printMatrix(const vvi &A){
	for(int i = A.size()-1; i >=0; i--){
		for(int j = A[0].size()-1; j>=0; j--){
			printf("%d, ", A[i][j]);
		}
		printf("\n");
	}
}
vvi generateMatrix(int A) {
	int n = A;
	if(n<=0) return vvi();
	vvi result(n, vi(n));
	int L = 0, R = n-1, T = 0, B = n-1;
	int val = 1, dir = 0;

	while(T<=B && L<=R){
		if(0==dir)	{
			// L to R
			for (int i = L; i <= R; ++i){
				result[T][i] = val++;
			}
			T++;
			dir = (dir+1) % 4 ;
		}else if(1 == dir){
			// T to B
			for (int i = T; i <= B; ++i){
				result[i][R] = val++;
			}
			R--;
			dir = (dir+1) % 4 ;
		}else if(2 == dir){
			// R to L
			for (int i = R; i >= L; --i){
				result[B][i] = val++;
			}
			B--;
			dir = (dir+1) % 4 ;
		}else if(3 == dir){
			// B to T
			for (int i = B; i >= T; --i){
				result[i][L] = val++;
			}
			L++;
			dir = (dir+1) % 4 ;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	// vector<vector<int> > A = {
 //    { 1, 2 },
 //    { 3, 4 },
 //    { 5, 6 }
	// };
	int A = 3;
	vvi result = generateMatrix(A);
	printMatrix(result);

	// tr(result, i){
	// 	printf("%d", *i) ; 	
	// }
	return 0;
}