#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* getNode(int data)
{
	Node* getNode = new Node;
	getNode->data = data;
	getNode->left = getNode->right = NULL;
	return getNode;
}


void convert(Node* root, Node** href)
{
	if(!root) return;
	convert(root->right, href);
	root->right = (*href);
	if((*href) != NULL) (*href)->left = root;
	*(href) = root;
	convert(root->left,href);
}

void print(Node* h)
{
	cout << "The converted DLL\n";
	while(h){
		cout << h->data <<" ";
		h = h->right;
	}
}

int main()
{
	Node* root = getNode(5); 
    root->left = getNode(3); 
    root->right = getNode(6); 
    root->left->left = getNode(1); 
    root->left->right = getNode(4); 
    root->right->right = getNode(8); 
    root->left->left->left = getNode(0); 
    root->left->left->right = getNode(2); 
    root->right->right->left = getNode(7); 
    root->right->right->right = getNode(9); 
	Node* href = NULL;
	convert(root,&href);
	print(href);
	return 0;
}