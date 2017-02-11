#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
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
bool isLeaf(tree root) {
	if(root->left == NULL && root->right == NULL) {
		return true;
  } else {
		return false;
  }
} 
bool isLevelOdd(int level) {
	if(level % 2) {
		return true;
  } else {
		return false;
  }

}
/* Method 1 */
void printDeepestOddLevelLeaf(tree root, int level, int &answer, int &deepestOddLevel) {
	if(!root) {
		return ;
  }
	if(isLevelOdd(level) && isLeaf(root)) {
		answer = root->data;
		deepestOddLevel = level;
		return ;
  }
	printDeepestOddLevelLeaf(root->left, level+1, answer, deepestOddLevel);
	printDeepestOddLevelLeaf(root->right, level+1, answer, deepestOddLevel);
}

/* Method 2 from geeksforgeeks */
int max(int a, int b) {
	return (a > b) ? a : b;
}

int getDepth(tree root, int level) {
	if(!root) {
		return 0;
  }
	if(isLeaf(root) && level&1) {
		return level;
  }
	return max(getDepth(root->left, level+1), getDepth(root->right, level+1));
}

int getDepthOfDeepestOddLevelLeaf(tree root) {
	int level = 1;
	return getDepth(root, level);
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
	int answer = INT_MIN;
	int deepestOddLevel = INT_MIN;
	printDeepestOddLevelLeaf(root, 1, answer, deepestOddLevel);
	cout << answer << " and level of node is " << deepestOddLevel  << endl;
  cout <<	"Level of node is " << getDepthOfDeepestOddLevelLeaf(root) << endl;
	return 0;  
}

