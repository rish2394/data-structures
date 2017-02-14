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
	if(root->left == NULL && root->right == NULL) {
		return true;
  }
  return false;
}
void fillLeaves(tree root, vector<int> &v) {
	if(!root) {
		return ;
  }	
	if(isLeaf(root)) {
		v.push_back(root->data);
  }
	fillLeaves(root->left, v);
	fillLeaves(root->right, v);
}
bool isEqual(vector<int> v1, vector<int> v2) {
	if(v1.size() != v2.size()) {
		return false;
  }
	for(int i=0; i<v1.size() && i<v2.size(); i++) {
		if(v1[i] != v2[i]) {
			return false;
    }
  }
  return true;
}
bool isLeafTraversalSame(tree A, tree B) {
	vector<int> v1, v2;
	fillLeaves(A, v1);
	fillLeaves(B, v2);
	return isEqual(v1, v2);
}
int main() {
	tree A = NULL;
	tree B = NULL;;
	int data;
	char ch;
	cout << "Press y to fill data for tree A: ";
	cin >> ch;
  while(tolower(ch) == 'y') {
		cout << "Enter data: ";
		cin >> data;
    createBinaryTree(A, data);
		cout << "Press y to fill more data: ";
	  cin >> ch;
  }
	cout << "Press y to fill data for tree B: ";
	cin >> ch;
  while(tolower(ch) == 'y') {
		cout << "Enter data: ";
		cin >> data;
    createBinaryTree(B, data);
		cout << "Press y to fill more data: ";
	  cin >> ch;
  }
	inorderTraversal(A);
  cout << endl;
	inorderTraversal(B);
  cout << endl;
	if(isLeafTraversalSame(A, B)) {
		cout << "True\n";
  } else { 
		cout << "False\n";
  }
	return 0;  
}

