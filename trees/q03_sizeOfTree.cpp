#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
#include<queue>
using std::queue;
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
int sizeOfTree(tree root) {
	if(!root) {
		return 0;
  }
	else {
		return sizeOfTree(root->left) + 1 + sizeOfTree(root->right);
  }
}
int sizeOfTreeIterative(tree root) {
	if(!root) {
		return 0;
  }
	int size = 0;
	queue<tree> q;
	q.push(root);
	while(!q.empty()) {
		tree temp = q.front();
		q.pop();
		if(temp->left) { 
			q.push(temp->left);
    }
		if(temp->right) { 
			q.push(temp->right);
    }
		size++;
  }
	return size;
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
	cout << "The size of tree is :" << sizeOfTree(root) << endl;
	cout << "The size of tree is :" << sizeOfTreeIterative(root) << endl;
	return 0;  
}
/* Recursive Method ->  Time Complexity - O(n) and Space Complexity - O(1) and if we consider function stack then it is O(n) */
/* Iterative Methd -> Time Complexity - O(n) and Space Complexity - O(n) */
