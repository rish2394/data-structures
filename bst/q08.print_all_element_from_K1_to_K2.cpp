#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
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
void printRange(tree root, int k1, int k2) {
	if(!root) { 
		return;
  }
	if(root->data > k1) {
		printRange(root->left, k1, k2);
	}
	if(root->data >= k1 && root->data <= k2) {
		cout << root->data << ' ';
  }
	if(root->data < k2) {
		printRange(root->right, k1, k2);
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
	int k1 , k2;
	cout << "Enter k1 and k2:";
	cin >> k1 >> k2;
	printRange(root, k1, k2);
	cout << endl;
	return 0;	
}
/* Time Complexity O(n) */
