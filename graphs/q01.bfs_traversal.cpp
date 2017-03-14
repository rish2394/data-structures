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
	g->n = n;
	g->m = m;
	g->arr = (AdjList*)malloc(g->n * sizeof(struct AdjList));
	// setting head pointer of all the indices to zero
	for(int i=0; i<g->n; i++) {
		g->arr[i].head = NULL;
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
		cout << endl;
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
	
	for(int i=0; i<g->m; i++) {
		cout << "Enter tw vertices to add an edge between them:";
		cin >> u >> v;
		list temp = createNode(v);
		temp->next = g->arr[u].head;
  	g->arr[u].head = temp;

  }	
}

// bfs of graph is very similiar to bfs of tree but here graph can contain cycles so we may come to the same node again and again 
// so to avoid processing node more than once we maintain a boolean array to check if that vertex is already processed or not
void bfs(graph g, int start) {
	bool visited[g->n];
	memset(visited, false, sizeof(visited));
	queue<int> q;
 	visited[start] = true;
	q.push(start);
	
	while(!q.empty()) {
		int nodeData = q.front();
		cout << nodeData << ' ';
		q.pop();
			
		list temp = g->arr[nodeData].head;
		while(temp) {
			if(visited[temp->data] == false) {
				visited[temp->data] = true;	
				q.push(temp->data);				
      }
			temp = temp->next;
    }
  }
}

int main() {
	int n, m;
	cout << "Enter number of vertices and number of edges:";
	cin >> n >> m;	
	graph g = (graph)malloc(sizeof(struct GraphNode));
	initialiseGraph(g, n, m);
	addEdge(g);
	printAdjList(g);
	cout << "bfs traversal is:";
	bfs(g, 2);
	cout << endl;
	return 0;
}


/* Time Complexity to do bfs O(V+E) */
// This algo leaves some vertices in disconnected graph
// This bfs algorithm is not valid where all the vertices are not reachable from a particular point.
// To visit every vertex we have to call the bfs function on every given vertex


