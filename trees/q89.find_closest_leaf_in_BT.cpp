#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
/* structure of the tree */
typedef struct node {
	char data;
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

void createBinaryTree(tree &root, char data) {
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
void minDistLeafUtil(tree root, int level, int &firstLevel) {
	if(!root) {
		return;
  }
	if(root->left == NULL && root->right == NULL) {
		if(level < firstLevel) {
			firstLevel = level;
    }
		return;
	}
	minDistLeafUtil(root->left, level + 1, firstLevel);
	minDistLeafUtil(root->right, level + 1, firstLevel);
}

int minDistLeaf(tree root) {
  int level = 0;
	int firstLevel = INT_MAX;
	minDistLeafUtil(root, level, firstLevel);
	return firstLevel;	
}
int distUtil(tree root, int &min, char key) {
	int dist = 0;
	if(!root) {
		return -1;
  }
	if(root->data == key) {
		dist = minDistLeaf(root);
		if(min > dist) {
			min = dist;
    }
		return 1;
  }
	int ld = distUtil(root->left, min, key);
	if(ld != -1) {
		if(root->right) {
			dist = ld + minDistLeaf(root);
			if(min > dist) {
				min = dist;
      }
    }
		else {
			return ld + 1;
    }	
  }
	int rd = distUtil(root->right, min, key);
	if(rd != -1) {
		if(root->left) {
			dist = 1 + minDistLeaf(root);
			if(min > dist) {
				min = dist;
      }
    }
		else {
			return rd + 1;
    }	
  }
	return -1;
}
int closestLeafDist(tree root, char key) {
	int min = INT_MAX;
	distUtil(root, min, key);	
	return min;
}

int main() {
	tree root = NULL;
	char data;
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
	char key;
	cout << "Enter key:";
	cin >> key;
  cout << "The closest distance leaf is " << closestLeafDist(root, key) << endl;
	return 0;  
}

/* Time Complexity - O(n) */
