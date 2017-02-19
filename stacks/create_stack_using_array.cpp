#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<climits>

struct stack {
	int capacity;
	int *arr;
	int top;
};
typedef struct stack *Stack;

struct stack* createStack(int capacity) {
	Stack s = (struct stack *)malloc(sizeof(struct stack));
	s -> capacity = capacity;
	s -> top = -1;
	s -> arr = (int*)malloc(s->capacity * sizeof(int));
	return s;
}

bool empty(Stack s) {
	return s->top == -1;
}
int capacity(Stack s) {
	return s->capacity;
}
int pop(Stack s) {
	if(empty(s)) {
		return INT_MIN;
  }
	int data = s->arr[s->top];
	s->top--;
	return data;
}

bool isFull(Stack s) {
	return	s->top >= s->capacity-1 ? true : false;
}

int size(Stack s) {
	return s->top + 1;	
}
int top (Stack s) {
	if(empty(s)) {
		return INT_MIN;
  }
	return s->arr[s->top];
}

void push(Stack &s, int key) {
  if(isFull(s)) {
		cout << "Overflow State, stack has " << capacity(s) << " capacity" << endl;
		return;
  } 
	s->top++;
	s->arr[s->top] = key;
}

void displayStack(Stack s) {
	cout << "Displaying Stack:\n";
	while(!empty(s)) {
		cout << "Top ELement is " << top(s) << endl;
		cout << "Popped ELement is " << pop(s) << endl;
  }
}
int main() {
	Stack s = createStack(100);
	push(s, 10);
	push(s, 11);	
  cout << "Stack top element is " << top(s) << endl;
	cout << "Stack size is " << size(s) << endl;
	cout << "Stack Capacity is " << capacity(s) << endl;
	cout <<	"Popped element is " << pop(s) << endl;
	push(s, 13);
	push(s, 1234);	
	displayStack(s);
	return 0;
}
/* Time Compelxities-> Push - O(1), Pop - O(1), Traverse - O(n) */


