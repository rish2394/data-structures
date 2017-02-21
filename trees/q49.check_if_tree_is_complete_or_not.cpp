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
/* Method 2 Recursive Approach*/
int totalNodes(tree root) {
	if(!root) {
		return 0;
  }
	return 1 + totalNodes(root->left) + totalNodes(root->right);
}

bool isCompleteTree2Util(tree root, int i, int count) {
	if(!root) {
		return true;
  }
	if(i >= count) {
		return false;
  }
	if(isCompleteTree2Util(root->left, 2*i + 1, count) && isCompleteTree2Util(root->right, 2*i + 2, count)) {
		return true;
  }
	return false;
}

bool isCompleteTree2(tree root) {
	int count = totalNodes(root);
	return isCompleteTree2Util(root, 0, count);
}
/* Method 1 */
bool isCompleteTree(tree root) {
	if(!root) {  
 		return true;
  }
	bool flag = false;
	queue<tree> q;
	q.push(root);
	while(!q.empty()) {
		tree temp = q.front();
		q.pop();
		if(temp->left) {
			if(flag == true) {
				return false;
      }
			q.push(temp->left);
    }
		else {
			flag = true;
    }
		if(temp->right) {
			if(flag == true) {  
				return false;
      }
			q.push(temp->right);
    }
		else {
			flag = true;
    }
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
  /* Method 1 - Iterative Method */
	if(isCompleteTree(root)) {
		cout << "True\n";
  }
	else {
		cout << "False\n";
  }
  /* Method 2 - Recursive Method */
	if(isCompleteTree2(root)) {
		cout << "True\n";
  }
	else {
		cout << "False\n";
  }
	return 0;  
}
/* Method 1 has Time Complexity O(n) and Space Complexity O(n) */
/* Method 2 has Time Complexity O(n) but requires two traversal of the tree and Space Complexity O(1) if functional stack is nt considered */

