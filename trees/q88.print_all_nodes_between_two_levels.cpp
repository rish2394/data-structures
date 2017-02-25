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
int treeHeight(tree root) {
	if(!root) {
		return 0;
  }
	return 1 + treeHeight(root->left) + treeHeight(root->right);
} 

void displayNodesUtil(tree root, int level) {
	if(!root) {
		return;
  }
	if(level == 1) {
		cout << root->data << ' ';
  }
  displayNodesUtil(root->left, level-1);
	displayNodesUtil(root->right, level-1);
}
/* Method 1 */
void displayNodes(tree root, int low, int high) {
	if(!root) {
		return ;
  }	
	int height = treeHeight(root);
	for(int i=low; i<=high && i<=height; i++) {
		displayNodesUtil(root, i);	
		cout << "\n";
  }
}
/* Method 2 */
void displayNodes2(tree root, int low, int high) {	
	if(!root) {
		return;
  }
	queue<tree> q;
	q.push(root);
	int level = 1;
	while(!q.empty()) {
		int count = q.size();
		while(count) {	
			tree temp = q.front();
			if(level >=low && level<=high) {	
				cout << temp->data << ' ';
			}
			if(temp->left) {
				q.push(temp->left);
      }
			if(temp->right) {
				q.push(temp->right);
      }
			q.pop();
		  count--;
    }
		cout << '\n' ;
		level++;
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
	int low, high;
	cout << "Enter low level and high level:";
	cin >> low >> high;
	displayNodes(root,low,high);
	displayNodes2(root,low,high);
	return 0;  
}
/* Method 1 - Time Complexity O(n^2) Space Complexity O(1) if functional stack is not considered*/
/* Method 2 - Time Complexity O(n) and Space Complexity O(n) */
