#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void printSorted(int arr[], int n, int i) {
	if(i >= n) {
		return;
  }	
	printSorted(arr, n, 2*i + 1);
	cout << arr[i] << ' ';
	printSorted(arr, n, 2*i + 2);
	
}
int main() {
	int arr[] = {20, 8, 22, 4, 12, 21, 24};
	int n = sizeof(arr)/sizeof(arr[0]);
	printSorted(arr, n, 0);
	cout << endl;
	return 0;
}
