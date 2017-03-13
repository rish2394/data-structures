#include<stdio.h>
#include<stdlib.h>

/* structure of the adjacency list node*/
struct AdjListNode {
	int data;
	struct AdjListNode *next;
};
typedef struct AdjListNode* list;

/* structure to represent an adjacency list */
struct adjList {
	struct AdjListNode *head;
};

/* structure to represent a graph */
struct GraphNode {
	int n; // Number of vertices
	int m; // Number of edges
	struct adjList *arr; // An array of pointers of linked list
};

/* pointer to the GraphNode */
typedef struct GraphNode *graph;

void initialiseGraph(graph g, int n, int m) {
	g->n = n;
	g->m = m;
	g->arr = (struct adjList*)malloc(g->n * sizeof(struct adjList));

	for(int i=0; i<g->n; i++) {
		g->arr[i].head = NULL;
  }
	
}

list createNode(int key) {
	list temp = (list)malloc(sizeof(struct AdjListNode));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void addEdge(graph g) {
	int u; // vertex 
	int v; // vertex

	for(int i=0; i<g->m; i++) {
		printf("Enter two vertex to add an edge between them:");
		scanf("%d%d",&u,&v);
		list temp = createNode(v);
		temp->next = g->arr[u].head;
		g->arr[u].head = temp;

		// since it is an undirected graph
		temp = createNode(u);				
		temp->next = g->arr[v].head;
		g->arr[v].head = temp;
  }
}

void printGraph(graph g) {
	for(int i=0; i<g->n; i++) {
		list temp = g->arr[i].head;
		printf("Adjacency List of vertex %d: \nHead", i);
		while(temp) {
			printf("->%d", temp->data);
			temp = temp->next;
    }
		printf("\n");
  }
	printf("\n");
}

int main() {
	int n; // n is number of vertices
	int m; // m is number of edges
	printf("Enter number of vertices and edges:");
	scanf("%d%d", &n , &m);
	graph g = (graph)malloc(sizeof(struct GraphNode));
	initialiseGraph(g, n, m);
	addEdge(g);
	printGraph(g);
	return 0;
}

/* Time Complexity: 
	initialiseGraph takes O(1)
	addEdge takes O(1) to add an edge
	printGraph takes O(V*E)
*/
