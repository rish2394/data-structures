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
/*
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
}*/ 

/* function to insert the data at beginning of the list */
/*
void createList(list &head, int data) {
		list temp = new node;
 		temp -> data = data;
		temp -> next = NULL;
 		
		temp->next = head;
		head = temp;
	
}
*/
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
	return 0;
}

/* Time Complexity - O(n) to insert at the end of the list */
/* Time Complexity - O(1) to insert at the beginning of the list */

/* Note - Time Complexity for insertion at end can be reduced to O(1) by maintaining a tail(end of the list) */ 
