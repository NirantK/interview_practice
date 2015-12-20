// MERGEKLIST
// https://www.interviewbit.com/courses/programming/topics/heaps-and-maps/problems/mergeklist/

// interviewbit used a priority queue, I solved this using a map
// after solving this, I realised I could have simply used a vi to store the elements instead of map
// hence, two things pending - despite solving this question correctly and before average time
//  1. Solve using vi, 2. Solve using priority queue
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define pb push_back 
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++) 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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

ListNode* mergeKLists(vector<ListNode*> &A) {
    std::map<int, int> map; // value:freq
    ListNode* ll;
    for (int i = 0; i < A.size(); ++i){
    	ll = A[i];
    	// printList(ll);
		while(ll!=NULL){
    		++map[ll->val];
    		ll = ll->next;
    	}
    }
    ListNode* temp = NULL;
    for(auto it = map.rbegin(); it != map.rend(); ++it){
    	printf("key:%d, value: %d\n", it->first, it->second);
    	for (int i = 0; i < it->second; ++i){
    		ListNode* newNode = (ListNode*) new ListNode(it->first);
    		newNode->next = temp;
    		temp = newNode;
    	}
	}
    return temp;
}

void klists(vector <ListNode*> &v, vi &x){
	ListNode* A = (ListNode*)new ListNode(x[0]);
	for (int i = 1; i < x.size(); ++i){
		insertAtEnd(x[i], A);
	}	
	v.push_back(A);
}

int main(int argc, char const *argv[]){
	vector<ListNode*> v;
	vi x = {1, 2, 3, 4};
	vi y = {1,14,15};
	vi z = {5, 7,11,13};
	vi w = {6, 8, 9};

	// ListNode* A = (ListNode*)new ListNode(x[0]);
	// for (int i = 1; i < x.size(); ++i){
	// 	insertAtEnd(x[i], A);
	// }
	klists(v, x);
	klists(v, y);
	klists(v, z);
	klists(v, w);
	for (int i = 0; i < v.size(); ++i){
		printList(v[i]);
		printf("\n");
	}
	ListNode* result = mergeKLists(v);
	printList(result);
	return 0;
}