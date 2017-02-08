#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstdlib>

/* structure of the linked list */
typedef struct node {
	int data;
	struct node *next;
}node;
typedef node *list;

struct AdjList {
 node *head;	
};

/* This is the structure of the graph */
struct GraphNode {
	int V; // Number of Vertices
	int E; // Number of Edges
	struct AdjList *arr;
};
typedef struct GraphNode* graph;

void initialiseGraph(graph g) {
	/* Allocating Memory for all the Vertices */
	g->arr = (struct AdjList*)malloc(g->V * sizeof(struct AdjList));
	for(int i=0; i<g->V; i++) {
		g->arr[i].head = NULL;
  }
}

list createNode(int data) {
	list temp = new node;
	temp -> data = data;
	temp->next = NULL;
	return temp;
}

void addEdge(graph g) {
	int u, v;
	for(int i=0; i<g->E; i++) {
		cout << "Enter two vertices to add an edge between them : ";
		cin >> u >> v;
		list temp = createNode(v);  
    /* Insertion at beginning of the adjcencyList */
		/* Adding an edge from src(u) to dest(v) */
		temp->next = g->arr[u].head;
		g->arr[u].head = temp;
		
		/* If undirected graph is Given */
		/* so also add an edge from dest(v) to src(u) */
   	temp = createNode(u);
		temp->next = g->arr[v].head;
		g->arr[v].head = temp;
	}
}

void printGraph(graph g) {
	if(!g) {
		return ;
  }
	for(int i=0; i<g->V; i++) {
		list temp = g->arr[i].head;
		cout << "Ajacency List of vertex " << i << ":\nHead";
		while(temp) {
			cout << "->" << temp->data;
			temp = temp->next;
    }
		cout << endl;
  }	
}
int main() {
	graph g;
  g = (graph)malloc(sizeof(struct GraphNode));
	cout << "Enter number of vertices and edges:";
	cin  >> g->V >> g->E;
	initialiseGraph(g);
	addEdge(g);
	printGraph(g);
	cout << endl;
	return 0;
}
/* Time Complexity
	 initialiseGraph - O(V)
	 printGraph - O(V + E)
	 addEdge - O(1)
   Adding an vertex - O(1) if realloc finds an empty chunk of memory adjacent to it and O(n) if the whole memory is 
											shifted to new address.
*/
