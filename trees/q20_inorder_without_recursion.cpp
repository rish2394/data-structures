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

void inorder(tree root) {
	if(!root) {
		return;
  }
	stack<tree> s;
	while(true) {
		while(root) {
			s.push(root);
			root = root->left;
    }
		if(s.empty()) {
			break;
    }	
		root = s.top();
		s.pop();
		cout << root->data <<  ' ';
		root = root->right;
  }
	cout << endl;
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
  cout << endl;
	inorder(root);
	return 0;  
}

