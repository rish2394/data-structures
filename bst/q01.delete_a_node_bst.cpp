#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
/* structure of the node of the tree */
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;

/* pointer to struct node */
typedef struct node* tree;

void inorder(tree root) {
	if(!root) {
		return ;
  }
	inorder(root->left);
	cout << root->data << ' ';
	inorder(root->right);
}
tree newNode(int data) {
	tree temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void createTree(tree &root, int data) {
	tree temp = newNode(data);
	if(!root) {
		root = temp;
		return ;
	}
	if(root->data > data) {
		createTree(root->left, data);
  }	else {
		createTree(root->right, data);
  }
}
tree minNode(tree root) {
	if(!root) {
		return root;
  }	
	if(root->left == NULL) {
		return root;
  }
	return minNode(root->left);
}
tree deleteNode(tree root, int key) {
	if(!root) {
		return root;
  }
	if(root->data > key) {
		root->left = deleteNode(root->left, key);
  }
	else if(root->data < key) {
		root->right = deleteNode(root->right, key);
  }
	else {
		/* If one child or both child is empty */
		if(root->left == NULL) {
			tree temp = root->right;
			delete root;
			return temp;
    }
		if(root->right == NULL) {   
			tree temp = root->left;
			delete root;
			return temp;
    }
    /* If neither of the child is empty */
    /* Method 1: Find the node with minimum value on right subtree 
			 Method 2: Find the node with maximum value on left subtree */
    // Replace the found node data with current root's data and call the deleteNode function on that node */
		tree temp = minNode(root->right);
	
		/* Replacing data */
		root->data = temp->data	;
		root->right = deleteNode(root->right, temp->data);		
	}
	return root;
}
int main() {
	tree root = NULL;
	int data;
 	char ch;
	cout << "Press y to enter data:";
	cin >> ch;
	while(tolower(ch) == 'y') { 
		cout << "Enter data:";
		cin >> data;
		createTree(root, data);
		cout << "Press y to enter more data:";
		cin >> ch;	
  }	
	inorder(root);
	cout << endl;
	int key;
	cout << "Enter the key to be deleted:";
  cin >> key;
  root =	deleteNode(root, key);
	inorder(root);
	cout << endl;
	return 0;	
}
