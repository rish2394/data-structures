#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#define R 4
#define C 4

bool isSafe(int maze[R][C], int x, int y, bool visited[R][C]) {
	if(x >= 0 && x < R && y >=0 && y < C && maze[x][y] == 0 && !visited[x][y]) {	
		return true;
  }
	else {
		return false;
  }
}
void getTotalWaysUtil(int maze[R][C], int x, int y, int &count, bool visited[R][C]) {
	if(x == (R-1) && y == (C-1)) {
		count++;
		return;
  }
	if(isSafe(maze, x, y, visited)) {
		visited[x][y] = true;
		getTotalWaysUtil(maze, x+1, y, count, visited);
		getTotalWaysUtil(maze, x, y+1, count, visited);
		visited[x][y] = false;
  }
}
int getTotalWays(int maze[R][C]) {
	int count = 0;
	bool visited[R][C];
	memset(visited, 0, sizeof(visited));
	getTotalWaysUtil(maze, 0, 0,count, visited);
	return count;
}

int main() {
	int maze[R][C] = {  {0,0,0,0},
										  {0,0,0,0},
									  	{-1,0,0,0},
										  {0,0,0,0}
										};
	cout << "The total number of ways to reach dst is " << getTotalWays(maze) << endl;
	return 0;
}

/* Time Complexity O(n^2) */
