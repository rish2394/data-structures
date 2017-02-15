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
bool isLeaf(tree root) {
	
	if(root->left == NULL && root->right == NULL)	{
		return true;
	} else {	
		return false;
  }
}

bool isSumProperty(tree root) {
	if(!root) {
		return true;
  }
	int x = 0, y = 0 ;
	if(isLeaf(root)) {
		return true;
  }
	if(root->left) {
		x = root->left->data;	
  }
	if(root->right) {
		y = root->right->data;
  }
	if(x+y == root->data && isSumProperty(root->left) && isSumProperty(root->right)) {
		return true;
  }	else {
		return false;
  } 
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
	if(isSumProperty(root)) {
		cout << "True\n";
  }	 else {
		cout << "False\n";
	}
	return 0;  
}

