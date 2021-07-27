#include <vector>
#include <algorithm>
using namespace std;
#define sz(a) int((a).size()) 
typedef vector <int> vi;

/* function to find median of any array*/
double median(const vector<int> &A){
	int sz = A.size();
	if(sz%2 == 0){
		return (A[sz/2 -1] + A[sz/2 + 1])/2;
	}
	else
		return A[sz/2];
}

double median2(int a, int b){
	// vi v = vi (a, b);
	// return median(v);
	return ((double)(a+b))/2.0;
}

double median3(int a, int b, int c){
	vi v = {a, b, c};
	return median(v);
}
double median4(int a, int b, int c, int d){
	vi v = {a, b, c, d};
	return median(v);
}

/*util function which calls other functions and handles cases*/
double getMedian(const vi &A, const vi &B){
	int N = sz(A);
	int M = sz(B);
	if (N==1){
		if(M==1){
			return median2(A[0], B[0]);
		}
		else if(M & 1){
			//bitwise hack to check if M is odd
			//this means M is infact, odd
			return median2(B[M/2], median3(A[0], B[M/2 - 1], B[M/2 +1]));
		}
		else{
			return median3(B[M/2], B[M/2 -1], A[0]);
		}
	}
	else if (N==2){
		if(M==2){
			return median4(A[0], A[1], B[0], B[1]);
		}
		else if(M&1){
			return median3(B[M/2], std::max(A[0], B[M/2 -1]), std::max(A[1], B[M/2 +1]));
		}
		return median4(B[M/2], B[M/2 - 1], std::max( A[0], B[M/2 - 2] ), 
			std::min( A[1], B[M/2 + 1] ));
	}
	int idxA = (N - 1)/2;
	int idxB = (M - 1)/2;
	if(A[idxA] <= B[idxB])
		return getMedian(vector<int> A(A.begin()+idx, A.end()), vector<int> B(B.begin(), B.end()-idxA));
	else
		return getMedian(vector<int> A(A.begin(), A.end()-idxA), vector<int> B(B.begin()+idxA), B.end());
}

/*driver function to make sure the util function getMedian gets called correctly*/
double findMedian(const vector<int> &A, const vector<int> &B){
	int N = sz(A);
	int M = sz(B);
	if (N<M)
		return getMedian(A, B);
	else
		return getMedian(B, A);
}
int main(int argc, char const *argv[]){
	/* code */
	return 0;
}