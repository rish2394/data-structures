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
int getLevel(tree root, int level, tree node) {
	if(!root) {
		return -1;
  }
	if(root == node) {
		return level;
  }
	int l = getLevel(root->left, level+1, node);
	if(l != -1) {
		return l;
  }
	return getLevel(root->right, level+1, node);
}
bool isSibiling(tree root, tree a, tree b) {
	if(!root) {
		return false;
  }
	if((root->left == a && root->right == b) || (root->right == a && root->left == b)) {
		return true;
  }
	if(isSibiling(root->left, a, b) || isSibiling(root->right, a, b)) {
		return true;
  } else {
		return false;
  }
}
bool areCousins(tree root, tree a, tree b) {
	if(!root) {
		return false;
  }
	if(getLevel(root, 0, a) == getLevel(root, 0, b) && !isSibiling(root, a, b)) {
		return true;
	}
	return false;
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
  tree a = root->left->left;
	tree b = root->right->right->right;
	if(areCousins(root, a, b)) {
		cout << "True\n";
  } else {
		cout << "False\n";
  }
	return 0;  
}
/* Time Complexity - O(n) */
