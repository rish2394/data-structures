#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
#include<stack>
using std::stack;
/* structure of the tree */
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;

typedef node *tree;

void displayStack(stack<tree> s) {
	while(!s.empty()) {
		cout << s.top() -> data << ' ';
		s.pop();
  }
}

void postorderTraversal(tree root) {
	if(!root) {
		return;
  }
	stack<tree> s1, s2;
	s1.push(root);
	while(!s1.empty()) {
		tree temp = s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left) {
			s1.push(temp->left);
    }
		if(temp->right) {
			s1.push(temp->right);
    }
  }
	displayStack(s2);
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
	postorderTraversal(root);
  cout << endl;
	return 0;  
}

/* Time Complexity - O(n) and Space Complexity - O(2n) , we're using two stacks */
