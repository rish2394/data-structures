#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<climits>
/* structure of the stack node */
struct stackNode {
	int data;
	struct stackNode *next; 
};


bool empty(struct stackNode* s) {
  return s == NULL;
}

int top(struct stackNode *s) {
	if(empty(s)) {
		return INT_MIN;
  }
	return s->data;
}
struct stackNode* createNode(int key) {
	struct stackNode *temp = (struct stackNode*)malloc(sizeof(struct stackNode));
	temp->data = key;
	temp->next = NULL;
	return temp;
}
void push(struct stackNode* &s, int key) {
	struct stackNode* newNode = createNode(key);
	newNode -> next = s;
	s = newNode;	
}

void pop(struct stackNode* &s) {
	if(empty(s)) {
		cout << "Underflow state\n";
		return;
  }
 	struct stackNode* temp = s;
	s = s->next;
	free(temp);
}

int size(struct stackNode *s) {
  int count = 0;
	while(s != NULL) {
		count++;
		s = s->next;
  }
	return count;
}

int main() {
	struct stackNode *s = NULL;
	push(s, 10);
	push(s, 12);
	cout << top(s) << endl;
	pop(s);
	cout << top(s) << endl;
	cout << size(s) << endl;
	pop(s);
	cout << top(s) << endl;
	cout << size(s) << endl;
  return 0;	
}
/* Time Complexity - push O(1), pop O(1), size O(n), top O(1), empty - O(1) */
/* Space - Not Fixed.It grows dynamically */
