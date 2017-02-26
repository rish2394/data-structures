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
bool isLeaf( tree root) {
	if(root->left == NULL && root->right == NULL) {  
		return true;
  }
	else {
		return false;
  }
}
tree pruneUtil(tree root, int k, int sum) {
	if(!root) {
		return root;
  }
	sum += root->data;
	root->left =  pruneUtil(root->left, k, sum);
	root->right = pruneUtil(root->right, k , sum);
	if(isLeaf(root) && sum < k) {
		delete(root);
		root = NULL;
  }
	return root;
}
tree pruneTree(tree root, int k)	{
	if(!root) {
		return NULL;
  }
	return pruneUtil(root, k, 0);
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
	cout << "Enter k: ";
	cin >> k;
	root = pruneTree(root, k);
	inorderTraversal(root);
  cout << endl;
	return 0;  
}
/* Time Complexity - O(n) */
