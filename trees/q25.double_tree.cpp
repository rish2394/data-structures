#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
/* structure of the tree */
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;

typedef node *tree;


/* function for inorder traversal */
void inorderTraversal(tree root) {
	if(!root) {
		return ;
  }
	inorderTraversal(root->left);
	cout << root->data <<' ' ;
	inorderTraversal(root->right);
}

void createBinaryTree(tree &root, int data) {
	tree temp = new node;
	temp->left = NULL;
	temp->data = data;
	temp->right = NULL;

	if(!root) {	
		root = temp;
		return ;
  }
	char ch;
	cout << "Press l to insert in left and otherwise for right:";
	cin >> ch;
  if(ch == 'l') { 
		createBinaryTree(root->left, data);
  } else {
		createBinaryTree(root->right, data);
  }
}
tree createNode(int data) {
	tree temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
/* Method 1 --- creating all the way from root to leaf */
void doubleTree(tree &root) {
	if(!root) {
		return ;
  }	
	int data = root->data;
	tree temp1 = createNode(data);
	
	temp1->left = root->left;
	root->left = temp1;
	if(root->left) {
		doubleTree(root->left->left);
  }
	doubleTree(root->right);
}
/* Method 2 --- first reach the leaf and start building from there to the root recursively */
void doubleTreeGFG(tree root) {
	if(!root) {
		return ;
  }
	doubleTree(root->left);
	doubleTree(root->right);
	
	tree temp = root->left;
	root -> left = createNode(root->data);
	root->left->left = temp;
}
int main() {
	tree root = NULL;
	int data;
	char ch;
	cout << "Press y to fill data: ";
	cin >> ch;
  while(tolower(ch) == 'y') {
		cout << "Enter data: ";
		cin >> data;
    createBinaryTree(root, data);
		cout << "Press y to fill more data: ";
	  cin >> ch;
  }
	inorderTraversal(root);
  cout << endl;
	doubleTree(root);
	inorderTraversal(root);
  cout << endl;
	doubleTree(root);
	inorderTraversal(root);
	
	cout << endl;
	return 0;  
}
/* Time Complexity - O(n) */
