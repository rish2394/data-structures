#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
#include<vector>
using std::vector;
#include<algorithm>
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

void fillVector(tree root, vector<int> &v) {
	if(!root) {
		return;
  }
	fillVector(root->left, v);
	v.push_back(root->data);
	fillVector(root->right, v);
}

void fillTree(tree root, vector<int> &v) {
	if(!root) {
		return ;
  }
	fillTree(root->right, v);
	root -> data = v.back();
	v.pop_back();
	fillTree(root->left, v);
	
}

void changeToBST(tree root) {
	vector<int> v;
	fillVector(root, v); // O(n)
	std::sort(v.begin(), v.end()); //O(nlogn) (it can be O(n^2) so instead of this use merge sort)
	fillTree(root, v); //O(n)
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
	cout << "The inorder of tree is:";
	inorderTraversal(root);
  cout << endl;
	changeToBST(root);
	cout << "The inorder of tree is:";
	inorderTraversal(root);
  cout << endl;
	return 0;  
}
/ Time Cmplexity - O(nlogn) and Space Complexity - O(n)

/* Another Algo to do this
	1. Convert the BT to DLL in-place - takes O(n)
	2. Sort the Linked list using Merge Sort - takes O(nlogn)
	3. Convert the DLL to BT again - takes O(n)

	This algo takes O(nlogn) time and O(1) Space
*/
