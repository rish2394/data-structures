// This is the implementation of circular queue using array, in simple queue implementation we cannot insert element inspite of the vacant position once the rear reaches
// the end so to overcome this condition we use circular queue
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<climits>

struct Queue {
	int front;
	int rear;
	int *arr;
	int size;
	int capacity;
};

struct Queue* createQueue(int capacity) {
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q -> capacity = capacity;
	q -> front = 0;
	q -> rear = capacity - 1;
	q->size  = 0;
	q -> arr = (int*)malloc(sizeof(int) * q->capacity);
	return q;
}

bool empty(struct Queue *q) {
	return q->size == 0;
}

bool full(struct Queue *q) {
	return q->size == q->capacity;
}

int front(struct Queue *q) {
	if(empty(q)) {
		return INT_MIN;
  }
	return 	q->arr[q->front];
}

void push(struct Queue* &q, int key) {
	if(full(q)) {
		cout << "Overflow state\n";
		return;
  }	
	q->rear = (q->rear + 1)%(q->capacity);
	q->arr[q->rear] = key;
	q->size = q->size + 1;
}

int pop(struct Queue* &q) {
	if(empty(q)) {
		cout << "Underflow state\n";
		return INT_MIN;
  }
	int item = q->arr[q->front];
	q->front = (q->front + 1)%(q->capacity);
	q->size = q->size - 1;
	return item;
}

int back(struct Queue *q) {
	if(empty(q)) {
		return INT_MIN;
  }
	return q->arr[q->rear];
}

int size(struct Queue *q) {
	return q->size;
}

int capacity(struct Queue *q) {
	return q->capacity;
}

int main() {
	struct Queue *q = createQueue(100);
	push(q, 10);
	push(q, 11);
	cout << "front: " << front(q) << endl;
	cout << "rear: " << back(q) << endl;
	cout << "Queue size: " << size(q) << endl;
	cout << "Queue Capacity: " << capacity(q) << endl;
  cout << "Popping: " << pop(q) << endl;	
  cout << "Popping: " << pop(q) << endl;
	push(q, 12);
	push(q, 23);
	push(q, 34);
	cout << "front: " << front(q) << endl;
	cout << "rear: " << back(q) << endl;
	cout << "Queue size: " << size(q) << endl;
	cout << "Queue Capacity: " << capacity(q) << endl;
  cout << "Popping: " << pop(q) << endl;	
  cout << "Popping: " << pop(q) << endl;	
  cout << "Popping: " << pop(q) << endl;
  cout << "Popping: " << pop(q) << endl;

	return 0;
}


