#include<iostream>
using std::cout;
using std::cin;
using std::endl;

/* structure of the linked list node */
struct AdjListNode {
	int data;
	struct AdjListNode *next;
};
// pointer to list 
typedef struct AdjListNode *list;

/* structure to represent Adjacency List */
struct AdjList {
	struct AdjListNode *head;
};

/* structure of the graph */
struct GraphNode {
	int n; // number of vertices
	int m; // number of edges
	struct AdjList *arr; // an array of linked list
	int *cc; // an array to check if there is a path between two vertices
};
// pointer to the GraphNode 
typedef struct GraphNode *graph;

void createGraph(graph g, int n, int m) {
	g->n = n;
	g->m = m;
	g->arr = (AdjList*)malloc(g->n * sizeof(struct AdjList));
	for(int i=0; i<g->n; i++) {
		g->arr[i].head = NULL;
  }
	g->cc = (int*)malloc(g->n * sizeof(int));
	for(int i=0; i<g->n; i++) {
		g->cc[i] = -1;
  }
}

void printAdjList(graph g) {
	for(int i=0; i<g->n; i++) {
		list temp = g->arr[i].head;
		cout << "Adjacency List of vertex " << i << ":\nHead";
		while(temp) {
			cout << "->" << temp->data;
			temp = temp->next;
    }
		cout << "\n";
	}
	cout << endl;
}

list createNode(int key) {
	list temp = (list)malloc(sizeof(struct AdjListNode));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void addEdge(graph g) {
	int u, v; // variables to represent vertex
	for(int i=0; i<g->m; i++) {
		cout << "Enter two vertices to add an edge between them:";
		cin >> u >> v;
		list temp = createNode(v);
		temp->next = g->arr[u].head;
		g->arr[u].head = temp;
	
		// since it is an undirected graph
		temp = createNode(u);
		temp->next = g->arr[v].head;
		g->arr[v].head = temp;		
  }		
}

void dfs(graph g, int src, bool marked[], int count) {
	marked[src] = true;
	g->cc[src] = count;
	list temp = g->arr[src].head;
	while(temp) {
		src = temp->data;
		if(marked[src] == false) { 
			dfs(g, src, marked, count);	
    }
		temp = temp->next;
  }		
}

int CC(graph g) {
	bool marked[g->n];
	int count = 0;
	
	memset(marked, false, sizeof(marked));
	for(int i=0; i<g->n; i++) {
		if(marked[i] == false) {
			dfs(g, i, marked, count);
			count++;
    }
  }
	return count;	
}

void printCCArray(graph g) {
	for(int i=0; i<g->n; i++) {
		cout << g->cc[i] << ' ';
  }
	cout << endl;
}

int main() {
	int n, m;
	cout << "Enter number of vertices and number of edges:";
	cin >> n >> m;
	graph g = (graph)malloc(sizeof(GraphNode));
	createGraph(g, n, m);
	addEdge(g);
	printAdjList(g);
	cout << "The total number of connected component is " << CC(g) << endl;
	cout << "This ds (g->cc) checks whether there is a path between two vertices in graph" << endl;
	printCCArray(g);
	
	int testcase = 5; 
	// checking whether there is a path between two vertices 
	int u, v; // variable to store vertex
	while(testcase) {
		cout << "Enter two vertex:";
		cin  >> u  >> v;
		if(g->cc[u] == g->cc[v]) {
			cout << "True, there is a path between two vertices\n";
 		}
		else {
			cout << "There is no path between two vertices\n";	
    }
		testcase--;
  }
	return 0;
}

/* Time Complexity
	createGraph O(1) for allocating space + O(V) to initialise
	addEdge O(1) to add an edge between two vertices
	printAdjList takes O(V + E)
	CC takes O(V + E) time because dfs call takes O(V + E) time
	printCCArray takes O(V) time
	
  Once dfs is done and the data structure g->cc is build then we query whether there is a path between two vertices in constant time

*/
