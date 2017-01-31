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

/* function to check if loop is present */

bool isLoop(list head) {
	/* using hare and tortoise algo */
  
	list slow = head;
	list fast = head;
	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
				return true;
    }
  }
  return false; 	
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
  /* setup ->  make loop for demonstration */
  //  head->next->next->next->next->next->next = head;
 
  if(isLoop(head)) {
 		cout << "Loop is present in the list\n";
  } else {
    cout << "No Loop present\nList:";
  	display(head);
    cout << endl;
  }
	return 0;
}

/* Time Complexity - O(n) */
