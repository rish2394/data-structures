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
int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a , int b) {
	return a > b ? a : b;
}
/* Method 1 */
int getMinDepth(tree root) {	
	if(!root) {
		return 0;
  }
	if(!root->left) {
		return getMinDepth(root->right) + 1;
  }
	if(!root->right) {
		return getMinDepth(root->left) + 1;
  }
	return min(getMinDepth(root->left), getMinDepth(root->right)) + 1; 	
}
int getMaxDepth(tree root) {
	if(!root) {	
		return 0;
  }
	return 1 + max(getMaxDepth(root->right), getMaxDepth(root->left));
}

/*Method 2 */
bool isLeaf(tree root) {
	if(root->left == NULL && root->right == NULL) {
		return true;
  }
	return false;
}
int getMinDepth2(tree root) {
	if(!root) {
		return INT_MIN;
  }
	queue<tree> q;
	int depth = 1;
	q.push(root); 
	while(!q.empty()) {
		int count = q.size();
		while(count--) {
			tree temp = q.front();
			q.pop();
			if(isLeaf(temp))
		 		return depth;
			if(temp->left) {
				q.push(root->left);
			}
			if(temp->right) {
				q.push(root->right);
    	}
  	}
		depth++;
	}
	return depth;
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
	/* Method 1 */
	cout << "The minimum depth and maximum depth is " << getMinDepth(root) << " " <<getMaxDepth(root) << endl;
	/* Method 2 for finding minimum depth*/
	cout << "The minimum depth is " << getMinDepth2(root) << endl; 
	return 0;  
}
/* Method 1 has Time Complexity of O(n) for both the cases and Space Complexity O(n) if function stack is considered */
// In Method 1 we have to traverse the whole tree to find the min depth, by using level order traversal if we break whenever we find the first leaf and return its
//	 depth(level)
/* Method 2 has O(n) Time Comeplxity in worst case but this method is better than method 1 on average case */
/* Method 2 has O(n) space Complexity */
