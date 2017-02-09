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
void print(vector<int> v) {
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
  }
	cout << endl;
}
bool printAncestors(tree root, int key, vector<int> &v) {
	if(!root) {
		return false;
  }
	if(root->data == key) {
		print(v);
		return true;
  }
	v.push_back(root->data);
	if(printAncestors(root->left, key, v) ||	printAncestors(root->right, key, v)) {
		return true;
  } else {
   	v.pop_back();
		return false;
  }
}
/* Method 2 without using extra space*/
bool printAncestors2(tree root, int key) {
  if(!root) {
		return false;
  }
	if(root->data == key) {
		return true;
  }
	if(printAncestors2(root->left, key) || printAncestors2(root->right, key)) {
		cout << root->data <<' ';
		return true;
  }
	else {
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
	int key;
	cout << "Enter Key:";
	cin >> key;
	vector<int> v;
  printAncestors(root, key, v);
	cout << endl;	
  printAncestors2(root, key);
	cout << endl;	
	return 0;  
}
/* Time Complexity - O(n) and Space Complexity - O(n) */
