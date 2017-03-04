/* Program for nth catalan number which is also equal to the number of possible BST with that Catalan number */
#include<time.h>
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

typedef unsigned long long u64_t;

/* Recursively Naive Method */
u64_t getCatalan(int n) {
	if(n <= 1) {
		return 1;
	}
	u64_t res = 0;
	for(int i=0; i<n; i++) {
		res += getCatalan(i) * getCatalan(n-i-1);
  }
	return res;
}

// This Problem has both Optimal Substructure and Overlapping Subproblem.So, a perfect candidate for DP 
/* A DP Method */
// This is the tabulation approach(bottom up approach)
u64_t getCatalanDP(int n) {

	// creating table 
	u64_t *cat = (u64_t*)calloc(n+1, sizeof(u64_t));
  
	// initialising value
	cat[0] = cat[1] = 1;
	
  
	for(int i=2; i<=n; i++) {
		for(int j=0; j<i; j++) {
			cat[i] += cat[j]*cat[i-1-j];
    }
  }
	u64_t res = cat[n];
	free(cat);
	return res;
}

/* Calculating nth catalan number using binomial coefficient*/
// This is DP approach to get Binomial Coefficient 
// Tabulation Form
int min(int i, int k) {
	return i > k ? k : i;
}

u64_t getBCUtil(int n, int k) {
  /* Creating Table */
	u64_t C[n+1][k+1]; 

  
	for(int i=0 ; i<=n; i++) {
		for(int j=0; j<=min(i, k); j++) {
			if(j==0 || i==j) {
				C[i][j] = 1;				
  		}
			else {
				C[i][j] = C[i-1][j-1] + C[i-1][j];
      }
    }
  }
	return C[n][k];
}

u64_t getCatalanBinomial(int n) {
	u64_t bc = getBCUtil(2*n, n);
	return bc/(n+1);
}

/* Solving using Binomial Coefficient Without DP*/
u64_t getCatalanBCUtil(int n, int k) {
	u64_t res = 1;
	if(k > n-k) {
		k = n-k;
  }
	for(int i=0; i<k ;i++) {
		res *= n-i;
		res /= i+1;
  }
	return res;
}
u64_t getCatalanBC(int n) {
	u64_t c = getCatalanBCUtil(2*n, n);
	return c/(n+1);
}
int main() {
	int n;
	cout << "Enter n:";
	cin >> n;
	/* Naive Method */
  clock_t tStart = clock();
	cout << getCatalan(n) << endl;
  printf("Time taken to solve recursively: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

  /* DP Method */
  tStart = clock();
	cout << getCatalanDP(n) << endl;
  printf("Time taken to solve using DP approach: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	/* Solving using Binomial Coefficient(Calculating BC using DP) */
  tStart = clock();
 	cout << getCatalanBinomial(n) << endl;
  printf("Time taken to solve using Binomial Coefficient(Using DP) approach: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	
 	
  /* Solving using Binmial Coefficient Without DP*/
  tStart = clock();
 	cout << getCatalanBC(n) << endl;
  printf("Time taken to solve using Binomial Coefficient approach without DP: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  
	return 0;
}

/* Naive Mehtod takes O(2^N) time 
	 DP Method takes O(N^2) time
	 Binomial Method with DP takes O(2N*N) time 
	 Binomial Method Withut DP takes O(N) time
