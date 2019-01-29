#include <bits/stdc++.h>
using namespace std;
int k,cnt;
struct Node{
    int data;
    Node* next;
};

Node* getNext(int data)
{
    Node* n = new Node;
    n->data = data;
    n->next = NULL;
    return n;
}

void printKRev(Node* h)
{
    if(!h)return;
    printKRev(h->next);
    cnt++;
    if(cnt <= k) cout << h->data << "  ";
}

int main() {
	
	Node* h = new Node;
	h->data = 1;
	h->next = getNext(2);
	h->next->next = getNext(3);
	h->next->next->next = getNext(4);
	h->next->next->next->next = getNext(5);
	cin >> k;
	printKRev(h);
	//cout << h->next->next->data;
	return 0;
}
