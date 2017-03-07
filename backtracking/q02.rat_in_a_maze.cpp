#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#define N 4

void printSol(int sol[][N]) {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
				cout << sol[i][j] << " ";
    }
		cout << endl;
  }
}

bool isSafe(int maze[][N], int x, int y) {
	if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
		return true;
  }
	return false;
}

bool solRatUtil(int maze[][N], int x, int y, int sol[][N]) {
	if(x == (N-1) && y == (N-1)) {
		sol[x][y] = 1;
		return true;
  }
	if(isSafe(maze, x, y)) {
		sol[x][y] = 1;
		if(solRatUtil(maze, x, y+1, sol)) {
			return true;
    }
		if(solRatUtil(maze, x+1, y, sol)) {
			return true;
    }
		 
		sol[x][y] = 0;// backtrack step;
  }
	return false;
}

void solRat(int maze[][N]) {
	int sol[][N] = { {0, 0, 0, 0},
                   {0, 0, 0, 0},
                   {0, 0, 0, 0},
                   {0, 0, 0, 0}
                 };
	if(!solRatUtil(maze, 0, 0, sol)) {
		cout << "No solution exist\n";
  }
	else {
		printSol(sol);
  }
}

int main() {
	int maze[][N] = { {1, 1, 0, 0},
										{0, 1, 0, 0},
										{0, 1, 1, 0},
										{1, 1, 1, 1}
									};
	solRat(maze);
	return 0;
}

/* Time Complexity - O(N^2) */
/* Space Complexity - O(N^2) */
