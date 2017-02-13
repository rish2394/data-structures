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
/* function for preorder traversal */
void preorderTraversal(tree root) {
	if(!root) {
		return ;
  }
	cout << root->data <<' ' ;
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
/* function for postorder traversal */
void postorderTraversal(tree root) {
	if(!root) {
		return ;
  }
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->data <<' ' ;
}
tree createNode(int key) {
	tree temp = new node;
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
}
int findIndex(int in[], int inStart, int inEnd, int key) {
	for(int i=inStart; i<= inEnd; i++) {
		if(in[i] == key) {
			return i;
    }
  }
	return -1;
} 
tree constructTree(int in[], int post[], int inStart,int inEnd, int &postIndex) {
	if(inStart > inEnd) {
		return NULL;
  }
	int data = post[postIndex--];
	tree root = createNode(data);
	if(inStart == inEnd) {
		return root;
  }
	int index = findIndex(in, inStart, inEnd, data);
	root->right = constructTree(in, post, index+1, inEnd, postIndex);
  root->left =	constructTree(in, post, inStart, index-1, postIndex);
	return root;
}
int main() {
  tree root = NULL;
	int in[] = {20, 10, 6, 5, 3, 30, 15};
	int post[] = {5, 3, 6, 10, 20, 15, 30};
	int postIndex = sizeof(post)/sizeof(post[0]) - 1; 
	root = constructTree(in, post, 0, 6, postIndex);
	cout << "Inorder Traversal:";
	inorderTraversal(root);
  cout << endl;
	cout << "Preorder Traversal:";
	preorderTraversal(root);
  cout << endl;
	cout << "Postorder Traversal:";
	postorderTraversal(root);
  cout << endl;
	return 0;  
}

