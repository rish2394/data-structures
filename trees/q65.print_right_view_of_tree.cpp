#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
#include<queue>
using std::queue;
#include<climits>
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
/* Recursive Method */
void printRightViewRecursiveUtil(tree root, int level, int &k) {
	if(!root) {
		return;
  }
	if(level > k) {
		cout << root->data << ' '; 
		k = level;
	}
	printRightViewRecursiveUtil(root->right, level+1, k);
	printRightViewRecursiveUtil(root->left, level+1, k);
}
void printRightViewRecursive(tree root) {
	if(!root) {
		return;
  }
	int k = INT_MIN;
	printRightViewRecursiveUtil(root, 1, k);
}

/* Iterative Method */
void printRightView(tree root) {
	if(!root) {
		return;
  }
	queue<tree> q;
	tree temp = NULL;
	q.push(root);
	while(!q.empty()) {
		int count = q.size();
		while(count--) {
			temp = q.front();
			q.pop();
			if(temp->left) {
				q.push(temp->left);
      }
			if(temp->right) {
				q.push(temp->right);
      }
    }
		cout << temp->data <<' ';
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
	/* Iterative Method */	
	printRightView(root);
	cout << endl;
	/* Recursive Method */
	printRightViewRecursive(root);
	cout << endl;
	return 0;  
}
/* Iterative Method: Time Complexity - O(n) and Space Complexity - O(n)
	 Recursive Method: Time Complexity - O(n) and Space Complexity - O(1) if functional stack is not considered
*/
