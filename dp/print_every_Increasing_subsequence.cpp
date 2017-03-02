#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<vector>
using std::vector;

void printIS(vector< vector<int> > L) {
	for(int i=0; i<L.size(); i++) {
		for(int j=0; j<L[i].size(); j++) {
      cout << L[i][j] << ' ';
    }
		cout << endl;
	}
} 
void getLIS(vector<int> v) {
	vector< vector<int> >L(v.size()); // 2d matrix for storing increasing subsequence
	L[0].push_back(v[0]);
	for(int i=1; i<v.size(); i++) {
		for(int j=0; j<i; j++) {
			if(v[i] > v[j] && L[i].size() < L[j].size() + 1) {
				L[i] = L[j];
      }
    }
		L[i].push_back(v[i]);
  }
  printIS(L);
}

int main() {
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
	getLIS(v);
	cout << endl;
	return 0;	
}
/* Time Complexity O(n^2) and Space Complexity O(L) */
