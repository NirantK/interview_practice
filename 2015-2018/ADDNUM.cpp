/*ADDNUM*/
/*Check the interviewbit solution too online; same logic, better implementation*/
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
void insertAtEnd(int x, ListNode *A){
	// head -> next = (ListNode*)malloc(sizeof(ListNode));
	// if(A==NULL){
		// A = (ListNode*) new ListNode(x);
	// }
	// else{
		ListNode* newNode = (ListNode*) new ListNode(x);
		while(A!=NULL && A->next!=NULL){
			A = A->next;
		}
		// newNode->val = x;
		newNode->next = NULL;
		A->next = newNode;
	// }
}
void printList(ListNode* A){
	while(A!=NULL){
		printf("%d ", A->val);
		A = A->next;
	}
}

ListNode* partition(ListNode* A, int B) {
	
}

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
	ListNode* res = new ListNode(0);
	ListNode* head = res;

	int carry = 0, sum = 0;
	while(A!=NULL && B!=NULL){
		sum = A->val + B->val + carry;
		// insertAtEnd(sum/10, answer);
		res -> next = new ListNode(sum%10);
		carry = sum / 10;
		// printf("carry: %d, val: %d\n", sum/10, sum%10	);
		A = A->next;
		B = B-> next;
		res = res -> next;
	}
	while(A!=NULL){
		sum = A->val + carry;
		res -> next = new ListNode(sum % 10);
		carry = sum / 10;
		A = A->next;
		res = res -> next;
	}
	while(B!=NULL){
		sum = B->val + carry;
		res -> next = new ListNode(sum % 10);
		carry = sum / 10;
		B = B->next;
		res = res -> next;
	}
	if (carry > 0){
		res ->next = new ListNode(carry);
	}
	return head->next;
}

int main(int argc, char const *argv[]){
	
	vi x = {2,4,3};
	vi y = {5,6,7,5};
	ListNode* A = (ListNode*)new ListNode(x[x.size()-1]);
	ListNode* B = (ListNode*)new ListNode(y[y.size()-1]); 
	ListNode* result = NULL;
	for (int i = x.size() - 2; i >=0 ; --i){
		insertAtEnd(x[i], A);
		// printf("%d\n", x[i]);
	}

	for (int i = y.size()-2; i >=0; --i){
		insertAtEnd(y[i], B);
	}
	// printList(A);
	// printf("-------------------\n");
	// printList(B);

	result = addTwoNumbers(A, B);
	printList(result);
}