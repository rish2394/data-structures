#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<queue>
using std::queue;

/* structure of the linked list node */
struct AdjListNode {
	int data;
	struct AdjListNode *next;
};

/* pointer to AdjList Node */
typedef struct AdjListNode* list;

/* structure to represent an AdjListNode */
struct AdjList {
	struct AdjListNode *head;
};

struct GraphNode {
	int n; // number of vertices
	int m; // number of edges
	struct AdjList *arr; // an array of linked list
};

/* pointer to the GraphNode structure */
typedef struct GraphNode *graph;

void initialiseGraph(graph g, int n, int m) {
	g->n = n+1;
	g->m = m;
	g->arr = (AdjList*)malloc(g->n * sizeof(struct AdjList));
	// setting head pointer of all the indices to zero
	for(int i=0; i<=g->n; i++) {
		g->arr[i].head = NULL;
  }
}

list createNode(int key) {
	list temp = new AdjListNode;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void addEdge(graph g) {
	int u, v; // used to save two vertices
	
	for(int i=1; i<=g->m; i++) {
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

bool isCyclic(graph  g) {
	bool visited[g->n];
	bool recStack[g->n];
    for(int i = 0; i < g->n; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

	/* iterating over the loop */
	for(int i=1; i<g->n; i++) {
		// if the vertices is not visited yet
			if(isCycleUtil(g, i, visited, recStack)) {
				return true;
    }
  }
	return false;
}

int main() {
	int t,n, m;
	cin >> t;
	while(t--) {
	    graph g = (graph)malloc(sizeof(struct GraphNode));
	    cin >>  n >> m;
	    initialiseGraph(g, n, m);
	    addEdge(g);
	    if(isCyclic(g)) {
	        cout << "1" << endl;
	    }
	    else {
	        cout << "0" << endl;
	    }
	}
	
	return 0;
}

