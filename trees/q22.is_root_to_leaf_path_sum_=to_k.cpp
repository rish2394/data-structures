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
/* Method 1 - by adding each node in a path and comparing it with the given sum 'k' */
bool isFound(tree root, int k, int sum) {
	if(!root) {
		return false;
	}
	sum += root->data;
	if(root->left == NULL && root->right == NULL && sum == k)	{
		return true;		
	}
	if(isFound(root->left, k, sum) || isFound(root->right, k, sum)) {
		return true;
  }
	return false;
}
/* Method 2 by finding the subsequent subSum */
bool isFound2(tree root, int k) {
	if(!root) {
		return false;
  }
	int subOfk = k - root->data;
	if(subOfk == 0 && root->left == NULL && root->right == NULL) {
		return true;
	}
	if(isFound2(root->left, subOfk) || isFound2(root->right, subOfk)) {
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
	int k;
	cout << "Enter k:";
	cin >> k;
	if(isFound(root, k, 0))	{
		cout << "True\n";
	}
	else {
		cout << "False\n";
	}
	if(isFound2(root, k))	{
		cout << "True\n";
	}
	else {
		cout << "False\n";
	}
	return 0;  
}
/* Time Complexity- O(n) processing each node once */
