/*nextPermutation*/
// Steps mentioned in the code are implemented as is from 
// https://www.wikiwand.com/en/Permutation#/Algorithms_to_generate_permutations
// Need to understand the logic better 
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



void nextPermutation(vector<int> &A){
		int sz = A.size();
        int k=-1;
        int l;
        //step1
        for (int i=0;i<sz-1;i++){
            if (A[i]<A[i+1]){
                k=i;
            }
        }
        if (k==-1){
            reverse(A.begin(),A.end());
            return;
        }
         
        //step2
        for (int i=k+1;i<sz;i++){
            if (A[i]>A[k]){
                l=i;
            }
        }
        //step3        
        int tmp = A[l];
        A[l]=A[k];
        A[k]=tmp;
        //step4
        reverse(A.begin()+k+1,A.end());
}

int main(int argc, char const *argv[])
{
	vi A = {1,2,3};
	nextPermutation(A);
	tr(A, it){
		printf("%d", *it);
	}
	vi B = {3,2,1};
	nextPermutation(B);
	tr(B, it){
		printf("%d", *it);
	}

	return 0;
}