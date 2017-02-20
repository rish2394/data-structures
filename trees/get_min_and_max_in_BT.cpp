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
int getMin(tree root) {
	if(!root) {
		return INT_MAX;
  }
	int leftMin = getMin(root->left);
	int rightMin = getMin(root->right);
	int min = leftMin > rightMin ? rightMin : leftMin;
	return root->data > min ? min : root->data; 
}
int getMax(tree root) {
	if(!root) {
		return INT_MIN;
  }
	int leftMax = getMax(root->left);
	int rightMax = getMax(root->right);
	int max = leftMax > rightMax ? leftMax : rightMax;
  return root->data > max ? root->data : max; 
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
	cout << "The maximum value and minimum value in binary tree is " << getMin(root) << " " << getMax(root) << " respectively " << endl;
	return 0;  
}

