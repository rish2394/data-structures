/* Ques - Given only a pointer to a node to be deleted in singly list, how would you delete it? */
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
/* function to swap two numbers */
void swap(int &a, int &b) {
	int temp = a;
  a = b;
	b = temp;
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
/* We are given the only pointer to the node itself which is to deleted */
/* move the data of the node to be deleted at the end and then delete it. */
/* This method wouldn't work if the node to be deleted is the last node */

void deleteGivenNode(list temp) {
	list prev_temp = temp;	
	while(temp->next) {
		swap(temp->data, temp->next->data);
		prev_temp = temp;
		temp = temp->next;
  }
  
  prev_temp->next = NULL;
  delete temp;
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
  cout << "\n";
  /* temp is given pointer, modify it to test different cases */
  list  temp = head;
  deleteGivenNode(temp);
  display(head);
  cout << endl;
	return 0;
}

/* Worst Case Time Complexity - O(n) when head is the pointer to be deleted we've to move it all the way to the end of the list*/
