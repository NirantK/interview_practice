/*REVERSELINKEDLIST*/
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
	while(A!=NULL){
		++count;
		A = A -> next;
	}
	return count;
}
ListNode* swap(ListNode* next1, ListNode* next2) {
        next1->next = next2->next;
        next2->next = next1;
        return next2;
    }
void insertAtEnd(int x, ListNode *A){
		ListNode* newNode = (ListNode*) new ListNode(x);
		while(A!=NULL && A->next!=NULL){
			A = A->next;
		}
		newNode->next = NULL;
		A->next = newNode;
}
void printList(ListNode* A){
	while(A!=NULL){
		printf("%d ", A->val);
		A = A->next;
	}
}
ListNode *reverseBetween(ListNode* head, int m, int n){
	ListNode* h = head;
	int k1, k2;
	for (int i = 0; i < n-m; ++i){
		k1 = m + i;
		k2 = n - i;
		if (k1>=k2){
			return head;
		}
		ListNode* p = h;
		ListNode* q = h;
		while(k1-1 > 0){p = p->next; --k1;}
		while(k2-1 > 0){q = q->next; --k2;}
		int temp = p->val;
		p->val = q->val;
		q->val = temp;
	}
	return head;
}


int main(int argc, char const *argv[]){
	vi x = {1,2,3};
	// vi y = {5,6,7,5};
	ListNode* A = (ListNode*)new ListNode(x[0]);
	// ListNode* B = (ListNode*)new ListNode(y[y.size()-1]); 
	for (int i = 1; i < x.size(); ++i){
		insertAtEnd(x[i], A);
	}
	printList(A);
	printf("\n");
	ListNode* result = reverseBetween(A, 2, 3);
	printf("\n");
	printList(result);
}