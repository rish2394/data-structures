#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
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
void preorderTraversal(tree root) {
	if(!root) {
		return ;
  }
	cout << root->data <<' ' ;
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
void postorderTraversal(tree root) {
	if(!root) {
		return ;
  }
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->data <<' ' ;
}
tree createNode(int data) {
	tree temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
int findIndex(int inorder[], int inStart, int inEnd, int key) {
	for(int k = inStart; k <= inEnd; k++) {
		if(inorder[k] == key) {
			return k;
    }
  }
	return -1;
}
tree buildTree(int inorder[], int preorder[], int inStart, int inEnd, int &preIndex) {
	if(inStart > inEnd) {
		return NULL;
  }
  tree root = createNode(preorder[preIndex++]);
	if(inStart == inEnd) {
		return root;
  }
	int inIndex = findIndex(inorder, inStart, inEnd, root->data);
	root->left = buildTree(inorder, preorder, inStart, inIndex-1, preIndex);
  root->right =	buildTree(inorder, preorder, inIndex+1, inEnd, preIndex);
	return root;
}

int main() {
	tree root = NULL;
	int inorder[] = {4, 2, 5, 1, 3, 6};
	int preorder[] = {1, 2, 4, 5, 3, 6};
	int preIndex = 0;
  root = buildTree(inorder, preorder, 0, 5, preIndex);
	cout << "Inorder:";
	inorderTraversal(root);
  cout << endl;
	cout << "Postorder:";
	postorderTraversal(root);
  cout << endl;
	cout << "Preorder:";
	preorderTraversal(root);
  cout << endl;
	return 0;  
}
/* Time Complexity - O(n^2), worst case occurs when the tree is left skewed */
