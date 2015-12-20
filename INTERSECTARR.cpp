/*INTERSECTARR*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 
// vector<int> reallyIntersect(const vector<int> &A, const vector<int> &B){
// 	return 0;
// }

vector<int> intersect(const vector<int> &A, const vector<int> &B) {
  int m = A.size()-1;
  int n = B.size()-1;
  int j = n;
  vector<int> answer;
  for (int i = 0; i <= m; ++i){
  	for (j=namespace; j >= i; --j){
  		if(A[i]==B[j]){
	  			// printf("%d, %d\n", A[i], B[j]);
				answer.push_back(A[i]);
				break;
		}
  	}
  }
  return answer;
}

int main(int argc, char const *argv[]){
	vector<int> A = {5,11,5};
	vector<int> B = {11,5};
	vector<int> intersection = intersect(A, B);
	tr(intersection, it){
		printf("%d", *it);
	}
	// intersect(A, B);
	// printf("Final Answer:%d\n", intersect(A, B));
	return 0;
}