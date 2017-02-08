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
bool isIdentical(tree A, tree B) {
	if((!A && B) || (A && !B)) {
		return false;
  }
	if(!A && !B) {
		return true;
  }
	if(A->data == B->data && isIdentical(A->left, B->left) && isIdentical(A->right, B->right)) {
		return true;
  }	else {
		return false;
  }
}
int main() {
	tree A = NULL;
	int data;
	char ch;
	cout << "Enter data for tree A:\n";
	cout << "Press y to fill data: ";
	cin >> ch;
  while(tolower(ch) == 'y') {
		cout << "Enter data: ";
		cin >> data;
    createBinaryTree(A, data);
		cout << "Press y to fill more data: ";
	  cin >> ch;
  }
	tree B = NULL;
	cout << "\nEnter data for tree B:\n";
	cout << "Press y to fill data: ";
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
	if(isIdentical(A, B)) {
		cout << "Both are identical\n";
	}	else {
		cout << "No\n";
  }
	return 0;  
}
/*Time Complexity O(min(n,m)) */
