#include<bits/stdc++.h>
using namespace std;

struct Node
{
	bool isEnd;
	Node* child[26];
};

Node* get(){
	Node* n = new Node;
	for(int i =0; i < 26;++i) n->child[i] = NULL;
	n->isEnd = false;
	return n;
}

void insert(string s, Node* r){
	Node* t = r;
	for(char c : s){
		if(!t->child[c-'a']) t->child[c-'a'] = get();
		t = t->child[c-'a'];
	}
	t->isEnd = true;
}

int main()
{
	vector<string> doc = {"apple" , "app" , "application" , "file" , "film"};
	Node* root = get();
	for(string w : doc) insert(w, root);
	if(root->child['f'-'a']) cout << "YES\n"; else cout << "NO\n";
	if(root->child['l'-'a']) cout << "YES\n"; else cout << "NO\n";
	return 0;
}