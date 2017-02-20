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

int diffSum(tree root) {
	if(!root) {
		return INT_MIN;
  }
	queue<tree> q;
	q.push(root);
	int level = 0;
	int sumOdd = 0, sumEven = 0;
	while(!q.empty()) {
		int count = q.size();
		while(count--) {
			tree temp = q.front();
			q.pop();
			if(level & 1) {
				sumEven += temp->data;
 			}	else {
				sumOdd += temp->data;
      }
			if(temp->left)	{
				q.push(temp->left);
			}
			if(temp->right)	{
				q.push(temp->right);
			}
    }
		level++;		
  }
	return sumOdd - sumEven;
}
/* Method 2 */
void diffSum2Util(tree root, int level, int &sumOdd, int &sumEven) {
	if(!root) {
	 return	;
  }
	if(level & 1) {
		sumOdd += root->data;
  }
	else {
		sumEven += root->data;
  }
	diffSum2Util(root->left, level+1, sumOdd, sumEven);
	diffSum2Util(root->right, level+1, sumOdd, sumEven);
}

int diffSum2(tree root) {
	if(!root) {
		return INT_MIN;	
  }
	int sumOdd = 0;
	int sumEven = 0;
	diffSum2Util(root, 1, sumOdd, sumEven);
	return sumOdd - sumEven;
}

/* Method 3 */
int diffSum3(tree root) {
	if(!root) {
		return 0;
  }
	return root->data - diffSum3(root->left) - diffSum3(root->right);
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
  
  /* Method 1 by level order traversal (by using queue) */
	cout << "The diffrence between odd level sum and even level sum " << diffSum(root) << endl;
	
	/* Method 2 by Recursion */
	cout << "The difference between odd level and even level sum " << diffSum2(root) << endl;
	
	/* Method 3 by Recursion (GFG) */
	cout << "The difference between odd level and even level sum " << diffSum3(root) << endl;
	return 0;  
}

/* Method 1 - Time COmplexity O(n) and Space Complexity O(n) */
/* Method 2 - Time Complexity O(n) and Space Complexity O(1) and if functional stack is considered then it is O(n) */
/* (Efficient)Method 3 - Time Comeplexity O(n) and Space Complexity O(1) and if functional stack is considered then it is O(n) */
