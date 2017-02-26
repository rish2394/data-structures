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
	}
	return false;
}
int getSumUtil(tree root, int sum) {
	if(!root) {
		return 0;
  }
	sum = root->data + 10*sum;
	if(isLeaf(root)) {
		return sum;
  }
	int ls = getSumUtil(root->left, sum);
  int rs = getSumUtil(root->right, sum);
	return ls + rs;
}
int getSum(tree root) {
	int sum = 0;
	return getSumUtil(root, sum);
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
	cout << "Total sum is: " << getSum(root) << endl;
	return 0;  
}
/* Time Complexity - O(n) */
