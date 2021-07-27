/*REMDUP*//*REMOVE DUPLICATES IN A SORTED VECTOR*/
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 

int removeDuplicates(vector<int> &A){
	int count = 0;
	int n = A.size();
    for (int i = 0; i < n; i++) { 
     	int j = i;
        if (j < n - 1 && A[j] == A[j+1]) ++j;
        else {
            // printf("count = %d, j = %d\n", count, j);
            A[count] = A[j];
            count++;
        }
    }
    A.erase(A.begin()+count, A.end());

    return count;

/*INTERVIEWBIT SOLUTION: It does not update the vector A, I do. :) */
	// int count = 0, n = A.size();
	// for (int i = 0; i < n; i++) { 
	// 	if (i < n - 1 && A[i] == A[i+1]) continue;
	// 	else {
	// 		A[count] = A[i];
	// 		count++;
	// 	}
	// }
	// return count;
}

int main(int argc, char const *argv[]){
	vector<int> A = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
	vi B = {1,1,2};
	printf("\nLength is %d\n", removeDuplicates(A));
	tr(A, it){
		printf("%d\n", *it);
	}
	// vvi::iterator row;
	// vector<int>::iterator col;
	// for (row = answer.begin(); row != answer.end(); ++row){
	// 	for(col = row->begin(); col != row->end(); ++col){
	// 		printf("%d ", *col);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}