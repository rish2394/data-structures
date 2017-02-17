#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<map>
using std::map;
typedef map<int, bool> Map;
typedef Map::iterator iter;

void fillArray(int a[], int n) {
	for(int i=0; i<n; i++) {
		cin >> a[i];
  }
}
void printPairs(int arr[], int n, int x) {
	Map myMap;
	for(int i=0; i<n; i++)	{
		iter it = myMap.find(x - arr[i]);
		if(it == myMap.end()) {
			myMap.insert(Map::value_type(arr[i], true));
    }
		else {
			cout << arr [i] << ' ' << it->first << endl;
    }
  }
}
int main() {
	int arr[100], n, x;
	cout << "Enter n:";
	cin >> n;
	fillArray(arr, n);
	cout << "Enter x:";
	cin >> x;
	printPairs(arr, n, x);
	cout << endl;
	return 0;
}
/* Time Complexity - O(nlogn) */
/* Traversing the whole array takes O(n) time and for each element we're searching the map which is by the RBT takes O(logn) time */
