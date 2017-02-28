#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
/* structure of the node of the tree */
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;

/* pointer to struct node */
typedef struct node* tree;

void inorder(tree root) {
	if(!root) {
		return ;
  }
	inorder(root->left);
	cout << root->data << ' ';
	inorder(root->right);
}
tree newNode(int data) {
	tree temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

tree createTree(int data) {
	return newNode(data);
}

tree toBST(int arr[], tree root, int beg, int end) {
	if(beg > end) {
		return NULL;
  }
	int mid = (beg + end)/2;
	root = createTree(arr[mid]);
	root->left = toBST(arr,  root->left, beg, mid-1);
	root->right = toBST(arr, root->right, mid+1, end);
	return root;
}
int main() {
	tree root = NULL;
	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
  root = toBST(arr, root, 0, n -1 );
	inorder(root);
	cout << endl;
	cout << height(root);
	return 0;	
}
/* Time Complexity - O(n) */
