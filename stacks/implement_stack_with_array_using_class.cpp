#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<climits>

class Stack {
	private:
		int top;
		int totalSpace;
		int *arr;
	public:
	Stack(int);
	void push(const int);
	bool empty();
	bool full();
	int peek();
	void pop();
	int capacity();
	int size();
};

Stack::Stack(int capacity) {
	top = -1;
	totalSpace = capacity;
	arr = (int*)malloc(this->totalSpace * sizeof(int));
}

bool Stack::full() {
	return top >= totalSpace-1;
}

int Stack::capacity() {
	return totalSpace;
}

bool Stack::empty() {
	return top == -1;
}

int Stack::size() {
	return top + 1;
}

int Stack::peek() {
	if(empty()) {
		return INT_MIN;
  }
	return arr[top];
}

void Stack::pop() {
	if(empty()) {
		cout << "Underflow state\n";
		return;
  }
	int data = arr[top--];
}

void Stack::push(int data) {
  if(full()) {
  	cout << "Stack Overflow";	
  	return;
  }		
	arr[++top] = data;	
}
void display(Stack s) {
	while(!s.empty()) {		
		cout << s.peek()<< ' ';
		s.pop();
  }
	cout << "\n";
}
int main() {
	Stack s(100); // This memory will be on stack, if we write like Stack *s = new Stack(100) now this allocated memory wil be on heap
	s.push(10);
	s.push(23);
	s.push(5);
	cout << "Stack Top Element: " << s.peek() << endl;
	cout << "Stack Size: " << s.size() << endl;
	cout << "Stack Capacity: " << s.capacity() << endl;
	s.pop();
	cout << "Stack Size: " << s.size() << endl;
	cout << "Stack Top Element: " << s.peek() << endl;
	cout << "Stack Capacity: " << s.capacity() << endl;
  s.pop();	
	cout << "Stack Size: " << s.size() << endl;
	cout << "Stack Top Element: " << s.peek() << endl;
	cout << "Stack Capacity: " << s.capacity() << endl;
	s.push(20);
	s.push(212);
	s.push(32);
	cout << "Stack Size: " << s.size() << endl;
	display(s);
	return 0;	
}
// Time Complexity -> push O(1), pop O(1), peek O(1), empty O(1), full O(1), size O(1), display O(n), capacity O(1)
