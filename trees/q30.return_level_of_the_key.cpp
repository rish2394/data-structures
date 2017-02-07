#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstring>
#include<climits>
#include<queue>
using std::queue;
/* structure of the tree */
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;

typedef node *tree;


void levelOrderTraversal(tree root) {
	if(!root) {
		return ;
  }
	queue<tree> q;
	q.push(root);
  int i=0;
	while(!q.empty()) {
		int count = q.size();
		cout << "Level " << i << ":";
		while(count) {
			tree temp = q.front();
			cout << temp->data << ' ' ;
			q.pop();
			if(temp->left) {
				q.push(temp->left);
    	}
    	if(temp->right) {
				q.push(temp->right);
    	}
			count--;
    }
		i++;
		cout << endl;
  }
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
int getLevelOfKey(tree root, int key) {
	if(!root) {
		return INT_MIN;
  }
	int level = -1;
	bool isFound  = false;
	queue<tree> q;
	q.push(root); 
	while(!q.empty()) {
	
  	int count = q.size();
		while(count) {
			tree temp = q.front();
			q.pop();
			if(temp->data == key) {
				isFound = true;
				break;
      }
			if(temp->left) {
				q.push(temp->left);
      }
			if(temp->right) { 
				q.push(temp->right);
      }
			count--;
    }
		++level;
		if(isFound) {
			break;
    }

  }
	if(!isFound) {
   	cout << "Key is not present in the tree returning garbage value ";
		return INT_MIN;
  } else {
  	return level;
 }
}

bool getLevel2(tree root, int key, int level, int &answer)  {
	if(!root) {
		return false;
  }
	if(root->data == key) {
		answer = level;
		return true;
	}
	if(getLevel2(root->left, key, level+1, answer) ||
				getLevel2(root->right, key, level+1, answer)) {
		return true;
	}

	return false;
}

int getLevel3(tree root, int key, int level) {
	if(!root) {
		return 0;
  }
	if(root->data == key) {
		return level;
  }
	int keyLevel = getLevel3(root->left, key, level+1);
	if(keyLevel != 0) {
		return keyLevel;
  }
	keyLevel = getLevel3(root->right, key, level+1);
	return keyLevel;
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
  levelOrderTraversal(root);
  cout << endl;
	int key;
	cout << "Enter key:";
	cin >> key;

  /* Method 1 has level starting frm 0 */
	cout << getLevelOfKey(root, key) << endl;

	/* Method 2 Starting level from 1*/
	int answer = 0;
  getLevel2(root, key, 1, answer);
	cout << answer << endl;
	
	/* Method 3 */
  cout << getLevel3(root, key, 1);
	cout << endl;
	return 0;  
}
/* Time Complexity for Level Order Traversal O(n) */
/* Time Cmplexity for iterative method O(n) */
/* Time Complexity for recursive method 2 and 3 ->O(n) */
