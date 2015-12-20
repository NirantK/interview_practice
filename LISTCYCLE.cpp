/*LISTCYCLE*/
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

ListNode *detectCycle(ListNode* head){
	ListNode* slow, *fast;
	slow = head;
	fast = head;
	fast = fast->next->next;
	slow = slow->next;
	while(slow && fast && fast->next){
		printf("\nFast:%d, ", fast->val);
		printf("Slow:%d", slow->val);
		if(slow == fast){
			return fast->next;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return NULL;
}

int main(int argc, char const *argv[]){
	vi x = {1,2,3,4, 5};
	// vi y = {5,6,7,5};
	ListNode* A = (ListNode*)new ListNode(x[0]);
	// ListNode* B = (ListNode*)new ListNode(y[y.size()-1]); 
	for (int i = 1; i < x.size(); ++i){
		insertAtEnd(x[i], A);
	}
	printList(A);
	// ListNode* curr = A;
	// while(curr->next!=NULL){
	// 	curr = curr->next;
	// }
	// A->next = A->next;
	// printList(A);
	ListNode* result = detectCycle(A);
	if(result!=NULL)
		printf("\nLoop Node Value: %d\n", result->val);
	else
		printf("\nNO Cycle");
}