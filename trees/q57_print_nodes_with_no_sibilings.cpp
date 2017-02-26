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
bool haveOneChild(tree root) {
	if((root->left && !root->right) || (root->right && !root->left)) {
		return true;
  }
	return false;
}
void printNodes(tree root) {
	if(!root) {
		return;
  }
	if(haveOneChild(root)) {
		if(root->left) {
			cout << root->left->data << ' ';
    }
		else {
			cout << root->right->data << ' ';
    }
  }
	printNodes(root->left);
	printNodes(root->right);
}
bool isLeaf(tree root) {
	if(root->left == NULL && root->rigth == NULL) {
		return true;
  }
	return false;
}
tree printNodes2(tree root) {
	if(!root) {
		return NULL;
		
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
	printNodes(root);
	printNodes2(root);
	cout << endl;
	return 0;  
}
/* Time Complexity - O(n) */
