#include<bits/stdc++.h>
using namespace std;

using cvi = const vector<int>&;
using vs = vector<string>;
using vvs = vector<vs>;
using vi = vector<int>;
using pii = pair<int,int>;
using umii = unordered_map<int,int>; 

/*
1,2,3,4,5,6,7,8
3,2,1 6,5,4 7,8
*/

struct ListNode {
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void print(ListNode* head) {
	ListNode* t = head;
	while(t) {
		cout << t->val << " -> ";
		t = t->next;
	}
	cout << endl;
}

// 1 -> 2 -> 3 -> 4 -> Null

ListNode* kRev(ListNode* head, int k) {
	int cnt = 0;
	ListNode* prev = nullptr;
	ListNode* curr = head;
	ListNode* next;
	while(++cnt <= k && curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	cout << "Cnt = " << cnt << endl;
	if(head) head->next = kRev(curr, k); 
	return prev;
}

int main() {
	int n = 7;
	ListNode* head = new ListNode(1);
	ListNode* temp = head;
	for(int i = 2; i <= 20; ++i) {
		temp->next = new ListNode(i);
		temp = temp->next;
	}
	print(head);
	int k = 3;
	ListNode* newHead = kRev(head, k);
	print(newHead);
	return 0;
}
