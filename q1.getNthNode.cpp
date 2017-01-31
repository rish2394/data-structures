#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string.h>
#include<climits>
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
/* function to get the nth node in the list , return INT_MIN if n > size of linked list */
int getNthNode(list head, int index) {
	int position = 1;
  while(head) {
		if(index == position) {
			return head->data;
    }
		head = head->next;
		position++;
  }
	return INT_MIN;
}
/* Recursively */
int getNthNodeRecursively(list head, int index, int position) {
  if(!head) {
    return INT_MIN;
  }
  if(index == position) {
    return head->data;
  }
  return getNthNodeRecursively(head->next, index, ++position);
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
  int index;
	cout << "Enter index:";
  cin >> index;
  cout << "The index = " << index << " node is: " << getNthNode(head, index) << "\n";
  cout << "The index = " << index << " node is: " << getNthNodeRecursively(head, index, 1) << "\n";

	return 0;
}
/* Iterative Methd
     Worst-Case-> Time Complexity - O(n) to get the nth node in the list
     Best Case-> Time Complexity O(1)
     Space Complexity -> O(1) in both case
*/

/* Recursive Method
      Worst-Case-> Time Complexity - O(n) Space Complexity - O(n)
      Best Case -> Time and Space Complexity O(1)
*/
