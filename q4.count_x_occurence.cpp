#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string.h>

typedef struct node {
	int data;
	struct node *next;
}node;

typedef node *list;

void display(list head) {
	if(!head) {
		return;
  }
	while(head) {
		cout << head->data << ' ';
		head = head->next;
  }
}

/* utility function to insert data at the end */
void createList(list &head, int data) {
	list temp = new node;
 	temp -> data = data;
	temp -> next = NULL;
	if(!head) {
		head = temp;
		return ;
  }
	list temp2 = head;
	while(temp2->next) {
		temp2 = temp2->next;
  }
	temp2->next = temp;
} 

/* function to get frequency of a particular number */
int getFreq(list head, int x) {
	if(!head) {
			return 0;
  }
  int count = 0;
	while(head) {
		if(head->data == x) {
			count++;
    }
		head = head->next;
  }
	return count;
}
/* Recursively - Bad Method */
int getFreqRecursively(list head, int x, int &count) {
	if(!head) {
		return 0;
  }	
  getFreqRecursively(head->next, x, count);
  if(head -> data == x) {
		count++;	
  }
  return count;
}
int main() {
	list head = NULL;
	int data;
	char ch;
	cout << "Press y to fill data:";
	cin >> ch;
	while(tolower(ch) == 'y') {
		cout << "Enter data:";
		cin >> data;
		createList(head, data);
		cout << "Press y to fill more data:";
		cin >> ch;
  }
	display(head);
  cout << endl;
  int x;
  cout << "Enter number whose frequency is to be calculated:";
	cin >> x;
	cout << x << " occurs " << getFreq(head, x) << " times in the list";
  cout << endl;
  int count = 0;
	cout << x << " occurs " << getFreqRecursively(head, x, count) << " times in the list";
  cout << endl;
	return 0;
}

/* Iterative Method: Time Complexity - O(n) and Space Complexity - O(1) */
/* Recursive Method: Time Complexity - O(n) and Space Complexity - O(n) */
