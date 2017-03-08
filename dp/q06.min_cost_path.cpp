#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<vector>
using std::vector;
#include<climits>
#define M 3
#define N 4
/* Allowed moves are right, bottom and diagonally lower cell*/

int min(int a, int b, int c) {
  int temp = a > b ? b : a;
	return temp > c ? c : temp;
}

/* Naive Method */
int getMinCost(int cost[][N], int m, int n, vector<int> &v) {
	if(m < 0 || n < 0) {	
		return INT_MAX;
  }
	if(m == 0 && n == 0) {
		return cost[m][n];
  }
	return cost[m][n] + min(getMinCost(cost, m-1, n, v) , getMinCost(cost, m, n-1, v), getMinCost(cost, m-1, n-1, v));
}

/* Using DP Method */
int getMinCostDP(int cost[M][N], int m , int n, vector<int> & v) {
	int sol[m+1][n+1];
	memset(sol, 0, sizeof(sol));
	
	sol[0][0] = cost[0][0];

	/* Initialising First Row */
	for(int i=1; i<=n; i++) {
		sol[0][i] = sol[0][i-1] + cost[0][i];
  }

	/* Initialising First Column */
	for(int i=1; i<=m; i++) {
		sol[i][0] = sol[i-1][0] + cost[i][0];
  }
 	
   
	// Main Part 
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {  
				sol[i][j] = min(sol[i-1][j], sol[i][j-1], sol[i-1][j-1]) + cost[i][j];
    }
  }
  	
	return sol[m][n];
}
	
void print(vector<int> v) {
		for(auto &i : v) {
				cout << i << ' ';
    }
		cout << "\n";
}
int main() {
	int cost[M][N] = {
										{1,3,5,8},
										{4,2,1,7},
										{4,3,2,3}
									 };
	vector<int> v;
	cout << "The minimum cost is " << getMinCost(cost, M-1, N-1, v) << endl;	
	cout << "The minimum cost is " << getMinCostDP(cost, M-1, N-1, v) << endl;	
	print(v);
	return 0;
}

/* Naive Method has Time Complexity O(2^n)
   and DP Method has Time Complexity O(m*n)
*/
