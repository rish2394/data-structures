#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
#include<climits>

/* structure of the node of the tree */
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;

/* pointer to struct node */
typedef struct node* tree;

void inorder(tree root) {
	if(!root) {
		return ;
  }
	inorder(root->left);
	cout << root->data << ' ';
	inorder(root->right);
}
tree newNode(int data) {
	tree temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
/* Utility function to insert in BST */
/* Time Complexity - O(logn) and in case of skewed tree it is O(n) same as linked list */
void createTree(tree &root, int data) {
	tree temp = newNode(data);
	if(!root) {
		root = temp;
		return ;
	}
	if(root->data > data) {
		createTree(root->left, data);
  }	else {
		createTree(root->right, data);
  }
}

/* Time Complexity - O(n) , worst case is when the tree is skewed */
int getMin(tree root) {
	if(!root) {
		return INT_MIN;
  }
	if(root->left == NULL) {
		return root->data;
  }
	return getMin(root->left);
}

/* Time Complexity - O(n) , worst case is when the tree is skewed */
int getMax(tree root) {
	if(!root) {
		return INT_MIN;
  }
	if(root->right == NULL) {
		return root->data;
  }
	return getMax(root->right);
}

/* Time Complexity - O(n) , worst case is when the tree is skewed */
bool isPresent(tree root, int key) {
	if(!root) {
		return false;
  }
	if(root->data == key || isPresent(root->left, key) || isPresent(root->right, key)) {
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
	cout << "Press y to enter data:";
	cin >> ch;
	while(tolower(ch) == 'y') { 
		cout << "Enter data:";
		cin >> data;
		createTree(root, data);
		cout << "Press y to enter more data:";
		cin >> ch;	
  }	
	inorder(root);
	cout << endl;
	cout << "The minimum and maximum element are :" << getMin(root) << " and " << getMax(root) << endl;
	int key;
	cout << "Enter the key to search:";
	cin >> key;
	if(isPresent(root, key)) { 	
		cout << key << " is present\n";
  }	else {
		cout << key << " is not present\n";
  }
	return 0;	
}
