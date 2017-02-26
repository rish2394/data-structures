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
	if(root->left == NULL && root->right == NULL) { 
		return true;
  }
	else { 
		return false;
  }
}
tree extractLeaves(tree root, tree &head) {
	if(!root) {
		return NULL;
	}
	if(isLeaf(root)) {
	  if(!head) {
		  head = root;	
    } else {
			root->right = head;
			head ->left = root;
			head = root;
    }
		return NULL;
  }
	root->right = extractLeaves(root->right, head);
	root->left = extractLeaves(root->left, head);
	return root;
}
void display(tree head) { 
	while(head) {
		cout << head->data << ' ';
		head = head->right;
  }
	cout << endl;
}
int main() {
	tree root = NULL;
	tree head = NULL;
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
	extractLeaves(root, head);
	display(head);
	return 0;  
}
/* Time Complexity - O(n) */
