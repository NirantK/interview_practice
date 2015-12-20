/*INTERSECTLIST*/
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int length(ListNode* A){
	int count = 0;
	while(A!=null){
		++count;
		A = A -> next;
	}
	return count;
}

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
	int m = length(A);
	int n = length(B);
	int d =  m - n < 0 ? n - m : m - n ;
	if(m > n){
		ListNode * temp = A;
		A = B;
		B = temp;
	}
	for (int i = 0; i < d; ++i){
		B = B->next;
	}
	while(A!=NULL && B!=NULL){
		if (A==B)
			return A;
		A = A -> next;
		B = B -> next;
	}
	return NULL;
}

int main(int argc, char const *argv[]){
	
	return 0;
}