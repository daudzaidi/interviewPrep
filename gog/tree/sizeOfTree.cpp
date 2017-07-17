#include <iostream>
using namespace std;


struct node{
	int data;
	node *left;
	node *right;
};

struct node* createNode(int x){
	node *newNode = new node;
	newNode->data =  x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
};

void PreOrder(node* root){
	if(root == NULL) return;
	cout << root->data;
	PreOrder(root->left);
	PreOrder(root->right);
}

int size(node *root){
	if(root == NULL) return 0;
	return size(root->left) + size(root->right)+1;
}

int main(){
	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->left->left = createNode(4);
	PreOrder(root);
	cout<< endl;
	cout << size(root);
}