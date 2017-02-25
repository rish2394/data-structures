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
bool isLeaf(tree root) {
	if(root->left == NULL && root->right == NULL) { 	
		return true;
  }
	else {
		return false;
	}
}
int getAnswer(tree root) {
	if(!root) {
		return INT_MIN;
  }
	queue<tree> q;
	q.push(root);
	int sum = 0, mul = 1;
	while(!q.empty()) {
		int count = q.size();
		while(count--) {
			tree temp = q.front();
			q.pop();
			if(isLeaf(temp)) { 
				sum += temp->data;
      }
			if(temp->left) {  
				q.push(temp->left);
      }
			if(temp->right) {
				q.push(temp->right);
      }
    }
		mul = sum == 0 ? mul : mul*sum;
		sum = 0;
  }
	return mul;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int heightTree(tree root) {
	if(!root) {
		return 0;
  }
	return 1 + max(heightTree(root->left), heightTree(root->right));
}
void getAnswerRecursiveUtil(tree root, int level, int &sum) {
	if(!root) {
		return;
  }
	if(level == 0 && isLeaf(root)) {
		sum += root->data;
  }
	getAnswerRecursiveUtil(root->left, level -1 , sum);
	getAnswerRecursiveUtil(root->right, level -1, sum);
}
int getAnswerRecursive(tree root) {
	int height = heightTree(root);
	int mul = 1;
	int sum = 0;
	for(int i=1; i<= height; i++) {
		getAnswerRecursiveUtil(root, i, sum);
		mul = mul * (sum == 0 ? 1 : sum);
		sum =0;
  }
	return mul;
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
	cout << "Multiplication of sum of leaves at each level is : "	 << getAnswer(root) << endl;
	/* Recursive Method */
	cout << "Multiplication of sum of leaves at each level is : "	 << getAnswerRecursive(root) << endl;
	
	return 0;  
}
/* 
	Iterative Method - Time Complexity O(n) and Space Complexity - O(n)
	Recursive Method - Time Complexity O(n^2) and Space Complexity - O(1) if functional stack is not considered
*/

