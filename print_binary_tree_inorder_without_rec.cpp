#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* getNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printTree(Node* root)
{
    stack<Node *>stk;
    Node* temp = root;
    
    while(!stk.empty() || temp)
    {
    	while(temp)
    	{
    		stk.push(temp);
    		temp = temp->left;
    	}
    	temp = stk.top(); stk.pop();
    	cout << temp->data << ' ';
    	temp = temp->right; 
    }

}

int main()
{
    Node* root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    printTree(root);
    return 0;
}