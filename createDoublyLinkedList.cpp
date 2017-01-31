#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string.h>

typedef struct node {
	struct node *prev;
	int data;
	struct node *next;
}node;

typedef node *list;

void display(list head) {
	if(!head) {
		return;
  }
	while(head)	{
		cout << head->data << ' ' ;
		head = head->next;
	}
	cout << endl;
}
/* function to insert the data at the end of the list */
void createList(list &head, int data) {
	list temp = new node;
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	
	if(!head) {
		head = temp;
		return ;
  }
	list temp2 = head;
	while(temp2->next) {	
		temp2 = temp2->next;
  }
	temp2->next = temp;
	temp->prev = temp2;
}

int main()	{
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
	return 0;
}
