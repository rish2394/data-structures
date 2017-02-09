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
bool mirrorUtil(tree t1, tree t2) {
	if(!t2 && !t2) {
		return true;
  }
	if(t1 && t2) {
		if(t1->data == t2->data && mirrorUtil(t1->left, t2->right) && mirrorUtil(t1->right, t2->left)) {
			return true;
    }
  }
	return false;
}
bool isMirrorItself(tree root) {
	if(!root) {
			return true;
  }
	tree t1 = root->left;
	tree t2 = root->right;
	if(mirrorUtil(t1, t2)) {	
		return true;
  } else {
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
	if(isMirrorItself(root)) {
		cout << "True\n";
  }
	else {
		cout << "False\n";
  }
	return 0;  
}
/* Time Complexity - O(n) */
