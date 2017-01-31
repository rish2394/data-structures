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
/* Iterative Method */
void reverseList(list &head) {
	list curr = head;
	list prev = NULL;
	list forw = NULL;
	
	while(curr) {
		forw = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forw;
  }		
  head = prev;
}
/* Recursive Method */
void reverseListRecursively(list &head) {
  		
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
  cout << "Original List:";
	display(head);
  cout << endl;
  reverseList(head);
  cout << "Reversed List:";
	display(head);
  cout << endl;
	return 0;
}

/* Time Complexity - O(n) */

