#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
#include<vector>
using std::vector;
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

/* Method 1 -> store the inorder traversal in an array and check if it is sorted and if it does then return true , otherwise false; */
void fillVector(tree root, vector<int> &v) {
	if(!root) {
		return;
  }
	fillVector(root->left, v);
	v.push_back(root->data);
	fillVector(root->right, v);
}
bool isVectorSorted(vector<int> v) {
	for(int i=1 ; i < v.size() ; i++) {
		if(v[i] <= v[i-1]) {
			return false;
    }
  }
	return true;
}
bool isBST(tree root) {
	if(!root) {
		return true;
  }
	vector<int> v;
	fillVector(root, v);
	return isVectorSorted(v);
}
/* Method 2 Assuming all are distinct values*/
bool isBST2(tree root) {
	if(!root) {
		return true;
  }
	if(root->left && root->left->data > root->data) {
		return false;
  }
	if(root->right && root->right->data < root->data) {
		return false;
  }
	if(!isBST2(root->left) || !isBST2(root->right)) {
		return false;
  }
	return true;
}
/* Method 3 */
// Correct but not efficient ad we're visiting one node multiple time 
int minNode(tree root) {
	if(root->left)	{
		return root->data;
  }
	return minNode(root->left);	
}
int maxNode(tree root) {
	if(root->right == NULL) {
		return root->data;
  }	
	return maxNode(root->right);
}
bool isBST3(tree root) {
	if(!root) {
		return true;
  }
	if(root->left && root->data < maxNode(root->left)) {
		return false;	
  }
	if(root->right && root->data > minNode(root->right)) {
		return false;
  }
	if(!isBST3(root->left) || !isBST3(root->right)) {
		return false;
  }
	return true;
}
// Method 4 Correct and also efficient 
// All Distinct values
bool isBST4Util(tree root, int min, int max) {
	if(!root) {
		return true;
  }
	if(root->data < min || root->data > max) {
		return false;
  }
	if(!isBST4Util(root->left, min, root->data-1) || !isBST4Util(root->right, root->data+1, max) ) {
		return false;
  } 
	return true;
} 
bool isBST4(tree root) {
	int max = INT_MAX, min = INT_MIN;
	return isBST4Util(root, min, max);
}
/* Method 5 using prev pointer */
bool isBST5Util(tree root, tree prev) {
	if(!root) {
		return true;
  }
	if(!isBST5Util(root->left, prev)) {
		return false;
  }
	if(prev != NULL && prev->data >= root->data) {
		return false;
  }
	prev = root;
	if(!isBSTUtil(root->right, prev)) {
		return false;
  }
	return true;
}

bool isBST5(tree root) {
	tree prev = NULL;
	return isBST5Util(root, prev);
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
	
	/* Method 1 - Using inorder traversal */
	if(isBST(root)) {
		cout <<  "true\n";
  }	else {
		cout <<  "false\n";
  }
	
	/* Method 2 - StraightForward but wrong */
	
  if(isBST2(root)) {
		cout << "true\n";
  }	else {
		cout << "false\n";
  }
	
	/* Method 3 - Correct but not efficient */
	if(isBST3(root)) {
		cout << "True\n";
  }	else {
		cout << "False\n";
  }

	/* Method 4 - Correct and also efficient */
	if(isBST4(root)) {
		cout << "True\n";
  } else {
		cout << "False\n";
  }

  /* Method 5 - Uisng Previous Pointer */	
	if(isBST5(root)) {
		cout << "True\n";
  } else {	
		cout << "False\n";
  }
	return 0;  
}







