#include <iostream>

struct node{
	int data;
	node *left;
	node *right;
};

struct node *newNode(int data){
	node *node  = new node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int main(){

	 node *root = newNode(1);
	 root->left = newNode(2);
	 root->right = newNode(3);

	 root->left->left = newNode(4);
}