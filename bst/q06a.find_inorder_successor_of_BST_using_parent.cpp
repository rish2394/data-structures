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
	struct node *parent;
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
void createTree(tree &root, int data) {
	tree temp = newNode(data);
	if(!root) {
		root = temp;
		return ;
	}
	if(root->data > data) {
		createTree(root->left, data);
  }	else {
		createTree(root->right, data);
  }
}
tree minValueNode(tree node) {
	if(!node) {
		return NULL;
  }
	if(node->left == NULL) {
		return node;
  }
	return minValueNode(node->left);
}

tree getSucc(tree root, tree target) {
	/* if target has right subtree then IS will lie there*/
	if(target->right) {
		return minValueNode(target->right);
  }
	tree p = target->parent;
	while(p != NULL && target == p->right) {
		target = p;
		p = p->parent;
  }
	return p;
}
int main() {
	tree root = NULL;
	int data;
 	char ch;
	cout << "Press y to enter data:";
	cin >> ch;
	while(tolower(ch) == 'y') { 
		cout << "Enter data:";
		cin >> data;
		createTree(root, data);
		cout << "Press y to enter more data:";
		cin >> ch;	
  }	
	inorder(root);
	cout << endl;
	/* setting parent pointer of each individual */
	root->parent = NULL;
	root->left->parent = root;
	root->right->parent = root;
	root->left->left->parent = root->left;
	root->left->right->parent = root->left;
	root->left->right->left->parent = root->left->right;
	root->left->right->right->parent = root->left->right;
	
	/* k node */
	tree target = root->left->right->right;
	cout << "The inorder successor of " << target->data << " is: " << getSucc(root, target)->data << endl; 	
	return 0;	
}

/* Time complexity - O(h) */
