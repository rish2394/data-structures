#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<climits>

struct Node {
	int data;
	struct Node *next;
};

class Stack {
	private: 
	  Node *top;
	public:
		Stack();
		int topData();
		void push(int);
		void pop();
		int size();
		bool empty();
		void swap(Stack &, Stack &);
};
Stack::Stack() 
  :top(NULL)
{
}
int Stack::size() {
	struct Node *temp = top;
	int count = 0;
	while(temp) { 
		count++;
		temp = temp->next;
  }
	return count;
}
int Stack::topData() {
	if(empty()) {
		return INT_MIN;
  }
	return top->data;
}

void Stack::pop() {
	if(empty()) {
		return;
  }
  struct Node *temp = top;
	top = top->next;
	delete temp;
}

struct Node* createNode(int key) {
	struct Node *temp = new struct Node();
	temp -> data = key;
	temp -> next = NULL;
	return temp;
}

void Stack::push(int key) {
	struct Node* newNode = createNode(key);	
	newNode->next = top;
	top = newNode; 
}

bool Stack::empty() {
	return top == NULL;
}
int main() {
	Stack *s = new Stack();
	s->push(27);
  s->push(10);
  cout <<  s->topData() << endl;
  cout <<  s->size() << endl;

	s->pop();
	cout << s->topData() << endl;
  cout <<  s->size() << endl;
  return 0;
}
// Time Complexity - push - O(1), pop - O(1), size - O(n), empty - O(1), topData - O(1)
