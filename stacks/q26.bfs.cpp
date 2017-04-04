#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<queue>
using std::queue;

/* structure of linked list node */
struct AdjListNode {
	int data;
	struct AdjListNode *next;
};
typedef struct AdjListNode* list;

/* structure to define Adjacency List */
struct AdjList {
	struct AdjListNode *head;
};

class Graph {
	private:
		int n; // stores no. of vertices
		int m; // stores no. of edges
		struct AdjList *arr;
	public:
		Graph(int, int);
		void addEdge();
		void displayGraph();
		void bfs(int);
};

Graph::Graph(int n, int m) 
			:n(n), m(m)
{
	arr = (struct AdjList*)malloc(sizeof(AdjList) * n);
	for(int i=0; i<n; i++) {
		arr[i].head = NULL;
  }
}

void Graph::displayGraph() {
	for(int i=0; i<n; i++) {
		list temp = arr[i].head;
		cout << "Adjacency List of vertex " << i << ":\nHead";
		while(temp) {
			cout << "->" << temp->data;
			temp = temp->next; 
    }
		cout << endl;
  }
	cout << "\n"; 
}

void Graph::bfs(int src) {
	bool visited[n];
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(src);
	while(!q.empty()) {
		int data = q.front();
		q.pop();
		cout << data << ' ';
		visited[data] = true;
		list temp = arr[data].head;
		while(temp) {
			data = temp->data;			
			if(visited[data] == false) {
				q.push(data);
				visited[data] = true;
      }
			temp = temp->next;
    }
  }
}

list createNode(int key) {
	list temp = (list)malloc(sizeof(struct AdjListNode));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void Graph::addEdge() {
	int u, v; // used to store user's input 
	for(int i=0; i<m; i++) {
		cout << "Enter two vertices to add an Edge:";	
		cin >> u >> v;
		list temp = createNode(v);
		temp->next = arr[u].head;
		arr[u].head = temp;

		//since it is an undirected graph
		temp = createNode(u);
		temp->next = arr[v].head;
		arr[v].head = temp;
		 	
  }
}

int main() {
	int n, m; // for storing verices and edges
	cout << "Enter number of vertices and edges: ";
	cin >> n >> m;
	Graph *g = new Graph(n, m);
	g->addEdge();
	g->displayGraph();
	int src;
	cout << "Enter source vertex:";
	cin >> src;	
	cout << "The bfs traversal of this graph is:";
	g->bfs(src);
	cout << endl;
	return 0;
}

// Time Complexities
/*
	addEgde - takes O(1) to add an edge
	bfs takes O(V+E) time and O(V+E) space
*/







