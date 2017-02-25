#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
#include<queue>
using std::queue;
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
/* Iterative Mehtod */
bool isComplete(tree root) {
	bool found = false;
	if(!root) {
		return true;
  }
	queue<tree> q;
	q.push(root);
	while(!q.empty()) {
		tree temp = q.front();
		q.pop();
		if(temp->left) {
			if(found == true) { 
				return false;
      }
			q.push(temp->left);
    }	else {
			found = true;
    }
		if(temp->right) {
			if(found == true) { 
				return false;
      }
		  q.push(temp->right);	
    }
		else {
			found = true;	
    }
  }
	return true;	
}
/* Recursive Method */
int countNodes(tree root) {
	if(!root) {
		return 0;
  }
	return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isComplete2Util(tree root, int index, int count) {
	if(!root) {
		return true;
  }
	if(index > count) {
		return false;
  }
	if(isComplete2Util(root->left, 2*index + 1, count) && isComplete2Util(root->right, 2*index + 2, count)) {
		return true;
  }
	return false;
}
bool isComplete2(tree root) {
	int count = countNodes(root);
	return isComplete2Util(root, 0, count);
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
	if(isComplete(root)) {
		cout << "True\n";
  }
	else {
		cout << "False\n";
  }
	/* Recursive Method */
	if(isComplete2(root)) {
		cout << "True\n";
  }
	else {
		cout << "False\n";
  }
	return 0;  
}

/* Time Complexity :
	 Iterative Method - O(n) and Space - O(n)
	 Recursive Method - O(n)	and Space - O(1) if functional stack is not considered 
*/
