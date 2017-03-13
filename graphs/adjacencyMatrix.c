#include<stdio.h>
#include<stdlib.h>

/* structure of the graph */
struct GraphNode {
	int n; // number of vertices
	int m; // number of edges
	int **arr;
};

/* pointer to the structure of the graph */
typedef struct GraphNode *graph;

void printAdjMatrix(graph g) {
	for(int i=0; i<g->n; i++) {
		for(int j=0; j<g->n; j++) {
			printf("%2d", g->arr[i][j]);
    }
		printf("\n");	
  }
}

void initialiseGraph(graph g, int n, int m) {
	g->n = n;
	g->m = m;
	g->arr = (int**)malloc(n * sizeof(int*));
	for(int i=0; i<g->n; i++) {
		g->arr[i] = (int*)malloc(n * sizeof(int));
  }
}

void addEdge(graph g) {
	int u, v;
	for(int i=0; i<g->m; i++) {
		printf("Enter the two vertices to add an edge between them:");
		scanf("%d%d", &u, &v);
		g->arr[u][v] = 1;
		
		// since it is an undirected graph
		g->arr[v][u] = 1;
  }
}

int main()  {
	int n, m;
	graph g = (graph)malloc(sizeof(struct GraphNode));
	printf("Enter number of vertices and edges:");
	scanf("%d%d", &n, &m);
	initialiseGraph(g, n, m);
	addEdge(g);
	printAdjMatrix(g);
	return 0;
}

/* Time Complexity
	 addEdge - O(1)
	 deleteEdge - O(1)
	 printAdjMatrix - O(V^2)
	 addVertex - O(V^2)
	 deleteVertex - O(d) where d is the degree of the vertex
*/
