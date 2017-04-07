#include<iostream>
using std::cout;
using std::cin;
using std::endl;

/* structure of the linked list */
struct AdjListNode {
	int data;
	struct AdjListNode *next;
};
// pointer to the AdjListNode
typedef struct AdjListNode *list;

/* structure to represent an Adjancency List */
struct AdjList {
	struct AdjListNode *head;
};

/* structure of the Graph node */
struct GraphNode {
	int n; // number of vertices
	int m; // number of edegs
	struct AdjList *arr; // an array of linked list
};
// pointer to the GraphNode
typedef struct GraphNode *graph;

void initGraph(graph g, int n, int m) {
	g->n = n;
	g->m = m;
	g->arr = (struct AdjList*)malloc(sizeof(struct AdjList) * g->n);
	for(int i=0; i<g->n; i++)	{
		g->arr[i].head = NULL;		
  }
}

void display(graph g) {
	for(int i=0; i<g->n; i++) {
		list temp = g->arr[i].head;
		cout << "Adjacency List of vertex " << i << ":\nHead" ;
		while(temp) {
			cout << "->" << temp->data;
			temp = temp->next;
    }
		cout << endl;
  }
}

list createNode(int key) {
	list temp = (list)malloc(sizeof(AdjListNode));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void addEdge(graph g) {
	int u, v; // variables to represent vertices
	for(int i=0; i<g->m; i++) {
		cout << "Enter two vertices to add an edge between them:";
		cin >> u >> v;
		list temp = createNode(v);
		temp->next = g->arr[u].head;
		g->arr[u].head = temp;
  }	
}

bool isCycleUtil(graph g, int v, bool visited[], bool recStack[]) {
	if(visited[v] == false) {
		visited[v] = true;
		recStack[v] = true;
	
		list temp = g->arr[v].head;
		while(temp) {
			int i = temp->data;
			if(!visited[i] && isCycleUtil(g, i, visited, recStack)) {
				return true;
    	}
			else if(recStack[i] == true) {
				return true;
    	}
			temp = temp->next;
  	}
  }
	recStack[v] = false;
	return false;	
}

bool isCycle(graph  g) {
	bool visited[g->n];
	bool recStack[g->n];
	memset(visited, false, sizeof(visited));
	memset(recStack, false, sizeof(recStack));

	/* iterating over the loop */
	for(int i=0; i<g->n; i++) {
		// if the vertices is not visited yet
			if(isCycleUtil(g, i, visited, recStack)) {
				return true;
    }
  }
	return false;
}

int main() {
	int n, m;
	graph g = (graph)malloc(sizeof(GraphNode));
	cout << "Enter numbere of vertices and edges:";
	cin >> n >> m;
	initGraph(g, n, m);
	addEdge(g);
	display(g);
	if(isCycle(g)) {
		cout << "Cycle is Present in the graph\n";
  } else {
		cout << "No Cycle is Present\n";
  }
	return 0;
}









