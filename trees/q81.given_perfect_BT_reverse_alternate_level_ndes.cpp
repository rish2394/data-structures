#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
#include<vector>
using std::vector;
#include<algorithm>
#include<queue>
using std::queue;
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
  	
/* Method 1 - By storing the odd level node data in an array and reverse the array and then store it back in tree */
void fillVectorWithOddLevelData(tree root, int level, vector<char> &v) {
	if(!root) {
		return;
  } 
	queue<tree> q;
	q.push(root);
	while(!q.empty()) {
		int count  = q.size();
		while(count) {
	    tree temp = q.front();
    	q.pop();
	    if(level & 1) { 
  	    v.push_back(temp->data);
    	}
    	if(temp->left) {
      	q.push(temp->left);
    	}
    	if(temp->right) {
      	q.push(temp->right);
    	}
			count--;
   	}
    level++;
  }
}	
void fillTreeWithVector(tree root, int level, vector<char> v) {
	if(!root) {
		
  }
}
void reverseAlternateLevel(tree root) {
	vector<char> v;
	int level = 0;
	fillVectorWithOddLevelData(root, level, v);
  std::reverse(v.begin(), v.end());
/*	for(int i=0; i<v.size(); i++) {
		cout << v[i] <<' ' ;
  }*/
	fillTreeWithVector(root, level, v);	
}

/* Method 3 */
void swap(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}
void reverseAlternateUtil(tree A, tree B, int level) {
	if(!A || !B) {
		return ;
	}
	if(level % 2 == 0) {
		swap(A->data, B->data);
  }
  reverseAlternateUtil(A->left, B->right, level+1);
  reverseAlternateUtil(A->right, B->left, level+1);	
}
void reverseAlternate(tree root) {
	int level = 0;
	reverseAlternateUtil(root->left, root->right, level);
}

/* Method 2 */
void fillVector(tree root, vector<char> &v, int level) {
	if(!root) {
		return;
  }
	fillVector(root->left, v, level+1);
	if(level & 1) {
		v.push_back(root->data);
  }
	fillVector(root->right, v, level+1);
}
void fillTree(tree root, vector<char> &v, int level) {
	if(!root) {
		return;
  }
	fillTree(root->left, v, level+1);
	if(level & 1) {
		root->data = v.front();
		v.erase(v.begin(), v.begin() +1);
  }
  fillTree(root->right, v ,level+1);
}
void reverseOddLevel(tree root) {	
	int level = 0;
	vector<char> v;
	fillVector(root, v, level);	
	std::reverse(v.begin(), v.end());
	fillTree(root, v, level);
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
  cout << "Original Tree:";
	inorderTraversal(root);
  cout << endl;
	
	/* Method 1 Uisng level order traversal */
	cout << "First Reversal:";
/*	reverseAlternateLevel(root);
	inorderTraversal(root); */
	cout << endl; 
	
	/*Method 2 using twice inorder traversal */
	cout << "Second Reversal:";
  reverseOddLevel(root);
	inorderTraversal(root);
	cout << endl;
	
	/* Method 3 Using Single Traversal */
	cout << "Third Reversal:";
	reverseAlternate(root);
	inorderTraversal(root);
  cout << endl;

	return 0;  
}

