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

/* function for preorder traversal */
void preorderTraversal(tree root) {
	if(!root) {
		return ;
  }
	cout << root->data <<' ' ;
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

/* function for postorder traversal */
void postorderTraversal(tree root) {
	if(!root) {
		return ;
  }
	postorderTraversal(root->left);
  postorderTraversal(root->right);
	cout << root->data <<' ' ;
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
	cout << "Inorder Traversal:";
	inorderTraversal(root);
  cout << endl;
	cout << "Preorder Traversal:";
	preorderTraversal(root);
  cout << endl;
	cout << "Postorder Traversal:";
	postorderTraversal(root);
  cout << endl;
	return 0;  
}
/* Time Complexity - O(n) for all traversals and
   Space Complexity -  O(n) if function stack is considered otherwise O(1)
*/
