#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
#include<vector>
using std::vector;
/* structure of the tree */
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;

/* pointer to node */
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
  /* Allocating space for the node */
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
void printVector(vector<int> v) {
	for(std::vector<int>::iterator it = v.begin() ; it != v.end() ; it++) {
		cout << *it << ' ';
  }
  cout << endl;
}
void printAllPaths(tree root, vector<int> v) {
	if(!root) {
		return ;
  }
	v.push_back(root->data);

	if(root->left == NULL && root->right == NULL) {
		printVector(v);
  }
	printAllPaths(root->left, v);
	printAllPaths(root->right, v);
	v.pop_back();
}
int main() {
	tree root = NULL;
	vector <int> v;
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
  cout << "All to root to leaf paths are:\n";
	printAllPaths(root, v);
	return 0;  
}

/* Time Complexity to create binary tree -> Average Case O(nh) height of the tree , Worst Case O(n2) */
