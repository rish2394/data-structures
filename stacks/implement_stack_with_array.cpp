#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<climits>

/* structure of the stack */
struct stack {
	int top;
	int capacity;
	int *arr;
};

struct stack* createStack(int capacity) {
	struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
	temp->capacity = capacity;
	temp->top = -1;
 	temp->arr = (int*)malloc(temp->capacity * sizeof(int));
	return temp;
}

bool empty(struct stack* s) {
	return s->top == -1;
}

bool full(struct stack *s) {
	return s->top >= s->capacity - 1;
}

void push(struct stack* s, int key) {
		if(full(s)) {
			cout << "Overflow state occured\n";
			return;
    }
		s->top++;
		s->arr[s->top] = key;
}

int pop(struct stack* s) {
	if(empty(s)) { 
		cout << "Underflow state\n";
		return INT_MIN;
  }
	int data = s->arr[s->top];
  (s->top)--;
	return data;
}
int size(struct stack *s) {
	return s->top + 1;
}
int top(struct stack* s) {
	return s->arr[s->top];
}

int capacity(struct stack *s) {
	return s->capacity;
}

void display(struct stack* s) {
  cout << "Elements in stack are: ";
	struct stack *temp = (struct stack*)malloc(sizeof (struct stack));
  memcpy(temp, s, sizeof(struct stack));
  
  while(!empty(temp)) {
		cout << top(temp) << ' '; 
		pop(temp);
  }
  free(temp);
	cout <<  "\n";
}

int main() {
	struct stack *s = createStack(100);
	push(s, 10);
	cout << "Stack Capacity: " << capacity(s) <<endl;
	cout << "Top Element: "  << top(s) << endl;
	cout <<  "Size of Stack: " << size(s) << endl;
	push(s, 20);
  push(s, 30);
	cout << "Stack Capacity: " << capacity(s) <<endl;
	cout << "Top Element: "  << top(s) << endl;
	cout <<  "Size of Stack: " << size(s) << endl;
	display(s);
	cout << "Popping: " << pop(s) << endl; 
	cout << "Popping: " << pop(s) << endl; 
	cout << "Popping: " << pop(s) << endl; 
	display(s);
	return 0; 	
}
/* Time Complexity-> capacity- O(1), top - O(1), size - O(1), push - O(1), pop - O(1) , full - O(1) , empty - O(1), display - O(n) */
