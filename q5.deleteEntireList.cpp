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
		cout << "List is empty";
		return;
  }
  cout << "List:";
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
/* function to delete the entire linked list */
void deleteEntireList(list &head) {
	list temp = NULL;
	while(head) {
		temp = head;
		head = head->next;
		delete temp;
  }	
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
  deleteEntireList(head);
	display(head);
  cout << endl;
	return 0;
}

/* Time Complexity - O(n) , to delete every node we have to traverse entire list */
