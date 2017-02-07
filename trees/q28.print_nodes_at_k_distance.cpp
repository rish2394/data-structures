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
void printNodesAtKDistance(tree root, int k, int level) {
	if(!root) {
		return ;
  }

	if(level > k) {
		return ;
  }
	
	if(k == level) {
		cout << root->data << ' ';
  }
	printNodesAtKDistance(root->left, k, level+1);
	printNodesAtKDistance(root->right, k, level+1);
}
void printNodesAtK(tree root, int k) {
  if(!root) {
		return ;
  }
	if(k == 0){
		cout << root->data << ' ';
	}
	printNodesAtK(root->left, k-1);
	printNodesAtK(root->right, k-1);

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
  printNodesAtKDistance(root, k, 0);
	cout << endl;
	printNodesAtK(root,k);
	cout << endl;
	return 0;  
}
/*For Both Methods written above Time Complexity O(n) and Space Complexity O(1) and if functional stack is considered then Space Cmplexity O(n) */

/* Another Method is through Level Order Traversal which takes O(n) time and O(n) space */
