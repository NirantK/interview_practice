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

vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// Directions
	// 0 - Right
	// 1 - Down
	// 2 - Left
	// 3 - Right
	int T = 0, B = sz(A)-1, L = 0, R = sz(A[0]) -1;
	int dir = 0; //initial direction is right
	while(T <=B && L <=R){
		if(0 == dir){
			// L to R
			for(int i = L; i <= R; i++){
				// printf("%d", A[T][i]);
				result.pb(A[T][i]);
			}
			T++;
			dir = (dir+1) % 4;
			// dir = 1;
		}
		else if(1 == dir){
			// T to B
			for (int i = T; i <= B; ++i)
			{
				// printf("%d", A[i][R]);
				result.pb(A[i][R]);
			}
			R--;
			dir = (dir+1) % 4;
			// dir = 2;
		}
		else if(2 == dir){
			// R to L
			for (int i = R; i>=L; --i){
				// printf("%d", A[B][i]);
				result.pb(A[B][i]);
			}
			B--;
			dir = (dir+1) % 4;
			// dir = 3;
		}
		else if(3 == dir){
			// B to T
			for (int i = B; i>=T; --i){
				// printf("%d", A[i][L]);
				result.pb(A[i][L]);
			}
			L++;
			dir = (dir+1) % 4;
			// dir = 0;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > A = {
    { 1, 2 },
    { 3, 4 },
    { 5, 6 }
	};
	// printMatrix(A);
	vector<int> result = spiralOrder(A);
	tr(result, i){
		printf("%d", *i) ; 	
	}
	return 0;
}