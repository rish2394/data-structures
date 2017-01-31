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

void display(list tail) {
	if(!tail) {
		return;
  }
	list temp = tail->next;
	do {
		cout << temp->data << ' ' ;
		temp = temp->next;
  }while(temp != tail->next);
}

/* utility function to insert data at the end */

void createList(list &tail, int data) {
	list temp = new node;
 	temp -> data = data;
	temp -> next = temp;

	if(!tail) {
		tail = temp;
		return;	
  }
	temp->next = tail->next;
  tail->next = temp;
	tail = temp;
} 

int main() {
	/* by maintaining tail instead of head it would take O(1) to insert at beginning or at end */
  list tail = NULL;
	int data;
	char ch;
	cout << "Press y to fill data:";
	cin >> ch;
	while(tolower(ch) == 'y') {
		cout << "Enter data:";
		cin >> data;
		createList(tail, data);
		cout << "Press y to fill more data:";
		cin >> ch;
  }
	display(tail);
  cout << tail->data;
  cout << endl;
	return 0;
}

/* Time Complexity - O(1) to insert at the end of the list */
/* Time Complexity - O(1) to insert at the beginning of the list */

