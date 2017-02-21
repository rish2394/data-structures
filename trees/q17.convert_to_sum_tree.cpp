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
/* Bad Method */
int convertSumTree(tree root) {
	if(!root) {
		return 0 ;
  }
  /* No need of this condition */
	if(root->left == NULL && root->right == NULL) {
		int temp = root->data;
		root->data = 0;
		return temp;
  }
  int oldData = root->data;
	root->data = convertSumTree(root->left) + convertSumTree(root->right);
	return oldData + root->data;
} 
/* God Method from GFG */
int toSumTree(tree &root) {
	if(!root) {
		return 0;
  }
	int oldData = root->data;
	root->data = toSumTree(root->left) + toSumTree(root->right);
  return oldData + root->data;	
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
  /*
 	convertSumTree(root);
  inorderTraversal(root);
	*/
	cout << "The sum of all elements is:" << toSumTree(root) << endl;
	inorderTraversal(root);
  cout << endl;
	return 0;  
}

/* Time Complexity O(n) for both method */
