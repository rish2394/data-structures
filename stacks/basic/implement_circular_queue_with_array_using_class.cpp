#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<climits>

class Queue {
	private:
		int totalCapacity;
		int size;
    int front;
		int rear;
		int *arr;
	public:
		Queue(int);
		int frontData();
		int rearData();
		void push(int);
		int pop();
		bool empty();
		bool full();
		int qsize();
		int capacity();
};

Queue::Queue(int capacity) 
			:totalCapacity(capacity)
			,size(0)
			,front(0)
			,rear(totalCapacity - 1)
{
	arr = (int*)malloc(sizeof(int) * totalCapacity);
}

bool Queue::empty() {
	return size == 0;
}

bool Queue::full() {
	return size == totalCapacity;
}

int Queue::frontData() {
 	if(empty()) {
		return INT_MIN;
  }	
	return arr[front];
}
int Queue::rearData() {
	
}

int main() {

}
