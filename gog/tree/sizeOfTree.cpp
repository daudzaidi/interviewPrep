#include <iostream>
#include <vector>
#include <stack>
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

int height(node *root){
	if(root == NULL) return 0;

	return max(height(root->left), height(root->right))+ 1;

}

void deleteTree(node * root){
	if(root == NULL) return ;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

void delete_tree(node **root){
	//if(*root == NULL) return; No need as null is already been checked above
	deleteTree(*root);
	*root = NULL;
}

node* swap(node* root){
	node* temp ;
	temp = root->right;
	root->right =root->left;
	root->left = temp;
	return root;
}

void makeMirror(node *root){
	if(root == NULL) return;


	 makeMirror(root->left);
	 makeMirror(root->right);
	 swap(root);
}




void printRootToleafPath(node *root, int path[], int pathlen){
	if(root == NULL) return;



	path[pathlen] = root->data;
	pathlen++;
	if(root->left == NULL & root->right == NULL){
			for(int i=0;i<pathlen;i++)
		cout << path[i] << " ";		
}else{
		printRootToleafPath(root->left, path, pathlen);

	

	printRootToleafPath(root->right, path, pathlen);
}


}	

int countLeafNodes(node *root){
	if(root == NULL) return 0;
	else if(root->left == NULL && root->right == NULL){
		return 1;
	}
	return countLeafNodes(root->left) + 
	countLeafNodes(root->right);
	//return countLeafNodes()
}

void levelOrderSpiral(node *root){
	stack<node*> s1;
	stack<node*> s2;
	s1.push(root);
	
while(!s1.empty() || !s2.empty()){

		while(!s1.empty()){
		cout << s1.top()->data<< " ";
		if(s1.top()->left != NULL)
			s2.push(s1.top()->left);
		if(s1.top()->right != NULL)
			s2.push(s1.top()->right);
		s1.pop();
	}

	while(!s2.empty()){
		cout << s2.top()->data<< " ";
		if(s2.top()->left != NULL)
			s1.push(s2.top()->left);
		if(s2.top()->right != NULL)
			s1.push(s2.top()->right);
		s2.pop();
	}
	
}


}


int main(){
	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->left->left = createNode(4);
	//root->left->left->left = createNode(4);
	PreOrder(root);
	// cout<< endl;
	// cout << size(root);
	// cout<< endl;
	// cout << height(root);
	//delete_tree(&root);
	//root = NULL;
	cout << endl;
	//PreOrder(root);
	//makeMirror(root);
	//PreOrder(root);
	//cout <<root->right->data;
	//cout <<root->right->left->data;
	// 	int pathlen = 0;
	// int path[10000] ;
	// printRootToleafPath(root, path, pathlen);

	//cout << countLeafNodes(root);
	levelOrderSpiral(root);
}