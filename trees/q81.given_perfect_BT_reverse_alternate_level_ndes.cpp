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

/* Method 1 */
void swapUtil(tree a, tree b) {
	int temp = a->data;
	a->data = b->data;
  b->data = temp;
}
void swapLevelData(tree arr[], int n) {
	int beg = 0;
	int end = n-1;
	while(beg<=end) {
		swapUtil(arr[beg], arr[end]);
		beg++;
   	end--;
  }	
}
void reverseAlternateLevel(tree root) {
	if(!root) {
		return;
  }
	int level = 0;
	tree arr[100];
	int i = 0;
	queue<tree> q;
	q.push(root);
	while(!q.empty()) {
		int count = q.size();
		while(count--) {
			tree temp = q.front();	
			q.pop();
			if(level & 1)	{	
				arr[i++] = temp;
				if(count == 0) {
					swapLevelData(arr, i);
        }
			}
			if(temp->left) {
				q.push(temp->left);
      }
			if(temp->right) { 
				q.push(temp->right);
      } 
    }
		level++;
		i = 0;
  }	
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
	reverseAlternateLevel(root);
	inorderTraversal(root); 
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

// Method 1 -> Time Complexity O(n) as we are visiting each node once
// Method 2 -> Time Complexity O(n) but two traversal and Space Complexity - O(n)
// Method 3 -> Time Complexity O(n) and Auxillary Space - O(1)
