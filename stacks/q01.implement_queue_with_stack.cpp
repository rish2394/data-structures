#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<stack>
using std::stack;
#include<climits>
#include<string>
using std::string;
#include<typeinfo>
template <class T>
class Queue {
	private:
		stack<T> s1;
		stack<T> s2;
	public:
		T front();
		T back();
		int size();
		bool empty();
	  T pop();
		void push(const T);	
};

template <class T>
bool Queue<T>::empty() {
	return s1.empty();
}

template <class T>
int Queue<T>::size() {
	return s1.size();
}

template <class T>
T Queue<T>::back() {
	if(s1.empty()) {
		return (T)INT_MIN;
  }
	while(!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
  }
	T data = s2.top();
	while(!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
  }
	return data;
}

template <class T>
T Queue<T>::front() {
	if(s1.empty()) {
		return (T)INT_MIN;
  }
	cout << "inside front\n";
	return s1.top();
}
template <class T>
void Queue<T>::push(const T key) {
	while(!s1.empty()) {	
		s2.push(s1.top());
		s1.pop();
  }
	s1.push(key);
	while(!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
  }
}

template <class T>
T Queue<T>::pop() {
	if(s1.empty()) {
		return (T)INT_MIN;
  }
	T data = s1.top();
	s1.pop();
	return data;
}

int main() {
	Queue<int> Q;
	Q.push(10);
	Q.push(20);
	Q.push(30);
	cout << "Queue size: " << Q.size() << endl;
	cout << "Queue front: " << Q.front() << endl;
	cout << "Queue Rear: " << Q.back() << endl;
	cout << "Popping " << Q.pop() << endl;
	cout << "Queue size: " << Q.size() << endl;
	cout << "Queue front: " << Q.front() << endl;
	cout << "Queue Rear: " << Q.back() << endl;
	cout << "Popping " << Q.pop() << endl;
	cout << "Queue size: " << Q.size() << endl;
	cout << "Queue front: " << Q.front() << endl;
	cout << "Queue Rear: " << Q.back() << endl;
	cout << "Popping " << Q.pop() << endl;
	cout << Q.empty() << endl;
	cout << "Queue size: " << Q.size() << endl;
	cout << "Queue front: " << Q.front() << endl;
	cout << "Queue Rear: " << Q.back() << endl;
	return 0;
}

/* Time Complexity
	 push - O(2n) ~= O(n)
 	 pop  - O(1)
	 size - O(1)
	 front - O(1)
	 back - O(2n) ~= O(n)
   empty - O(1)
*/	 
