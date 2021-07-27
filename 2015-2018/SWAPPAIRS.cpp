/*SWAPPAIRS*/
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

ListNode* swapPairs(ListNode* head){
	ListNode* current = new ListNode(0);
	current->next = head;
	head = current;
	// ListNode * temp;
	// int n = 0;

	// while(NULL!=current->next->next && NULL!=current->next){
	while(true){
		// if(0==n%2)
		// 	n=0;
		// if(0==n){
		if (current->next==NULL){break;}
		if (current->next->next==NULL){break;}
		ListNode* nextNode = current->next;
		ListNode* SkipNode = nextNode->next;
		nextNode->next = SkipNode->next;
		SkipNode->next = nextNode;
		current->next = SkipNode;


		current = nextNode;
		}
		// ++n;
		// current = current->next;
	// }
	return head->next;
}

/*INTERVIEWBIT SOLUTION*/
// ListNode *swapPairs(ListNode *head) {
//         ListNode* start = new ListNode(0); //make head no longer a special case
//         start->next = head;

//         ListNode *cur = start;
//         while (cur->next != NULL && cur->next->next != NULL) {
//             cur->next = swap(cur->next, cur->next->next);
//             cur = cur->next->next;
//         }
//         return start->next;
//     }
//     ListNode* swap(ListNode* next1, ListNode* next2) {
//         next1->next = next2->next;
//         next2->next = next1;
//         return next2;
//     }


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
	ListNode* result = swapPairs(A);
	printf("\n");
	printList(result);
}