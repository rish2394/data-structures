#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<queue>
using std::queue;
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
/* Iterative Method */
bool haveOneChild(tree temp) {
	if((temp->left == NULL && temp->right != NULL) || (temp->right == NULL && temp->left != NULL) ) {
		return true;
  }
	return false;
}
bool isFullTree(tree root) {
	if(!root) {
		return true;
  }
	queue<tree> q;
	q.push(root);
	while(!q.empty()) {
		tree temp = q.front();
		q.pop();
		if(haveOneChild(temp)) {
			return false;
    }
		if(temp->left) {
			q.push(temp->left);
    }
		if(temp->right) {
			q.push(temp->right);
    }
  }
	return true;
	
}
bool isFullTree2(tree root) {
	if(!root) {
		return true;
  }
	if(haveOneChild(root)) {
		return false;
  }
	if(!isFullTree2(root->left) || !isFullTree2(root->right)) {
		return false;
  }
	return true;
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
  /* Iterative Method */
	if(isFullTree(root)) {
		cout << "True\n";
  } else {
		cout << "False\n";
  }
	/* Recursive Method */
	if(isFullTree2(root)) {
		cout << "True\n";
  } else {	
		cout << "False\n";
  }
	return 0;  
}
/* Time Complexity:
   Iterative Method - O(n) and efficient
	 Recursive Method - O(n)
*/
