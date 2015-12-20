/*PARTITION*/
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

ListNode* partition(ListNode* A, int x) {
	ListNode* curr = new ListNode(0);
	curr->next = A;
	A = curr; //updating the head ptr to new node inserted at beginning
	ListNode* last = A; //ptr to find the last node of the list

	if(A==NULL || A->next==NULL)
		return A;

	int count = 0;
	while(last->next!=NULL){
		last = last->next;
		++count;
	}
	// printf("\n%d", last->val);
	printf("\nFound the last node\n");
	while(count > 0){
		// if(curr->val < x){
			
		// }else{
		// 	last->next = new ListNode(curr->val);
		// 	last = last->next;
		// }
		// curr = curr -> next;
		// --count;
		if (curr->next->val < x){  // val<x keep the node
                curr=curr->next;
                // --n;
        }else{                  // val>=x move to last
            last->next = new ListNode(curr->next->val);    // add node to the last
            last = last->next;
            curr->next = curr->next->next;                    //delete current node
        }
		--count;
	}
	return A->next;
}



int main(int argc, char const *argv[]){
	vi x = {1,4,3,2,5,2};
	// vi y = {5,6,7,5};
	ListNode* A = (ListNode*)new ListNode(x[0]);
	// ListNode* B = (ListNode*)new ListNode(y[y.size()-1]); 
	for (int i = 1; i < x.size(); ++i){
		insertAtEnd(x[i], A);
	}
	printList(A);
	ListNode* result = partition(A, 3);
	printList(result);
}