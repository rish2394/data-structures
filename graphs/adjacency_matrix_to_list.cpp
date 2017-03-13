#include<iostream>
using std::cout;
using std::cin;
using std::endl;

typedef struct node {
	int n; // number of vertices 
	int m; // number of edges;
	int **arr;
}node;
typedef node* graph;

// structure of the adjacency list node
struct AdjListNode {
	int data;
	struct AdjListNode* next;	
};
// pointer to AdjListNode
typedef struct AdjListNode *list;


// structure to represent adjacency list
struct AdjList {
	struct AdjListNode *head;
};

struct GraphNode {
	int n; // n is number of vertices
	int m; // m is number of edges
	AdjList *arr; // array of pointer of type AdjList
};
// pointer to GraphNode
typedef struct GraphNode* graphList;

void initialiseGraph(graph g, int n, int m) {
	g->n = n;
	g->m = m;
	g->arr = (int**)malloc(n*sizeof(int*));
	for(int i=0; i<n; i++) {
		g->arr[i] = (int*)calloc(n, sizeof(int));
  }
}

void fillMatrix(graph g) {
	int n1; // vertex one
	int n2; // vertex two
	for(int i=0; i<g->m; i++) {
		cout << "Enter the two vertices to add an edge between them:";
		cin >> n1 >> n2;
		g->arr[n1][n2] = 1;
		g->arr[n2][n1] = 1; // since it is an undirected graph
  }
}

void printMatrix(graph g) {
	for(int i=0; i<g->n; i++) {
		for(int j=0; j<g->n; j++) {
			cout << g->arr[i][j] << ' ';		
    }
		cout << "\n";
  }
	cout << endl;
}

void printGraphList(graphList gList) {
	for(int i=0; i<gList->n; i++) {
		list temp = gList->arr[i].head;
		cout << "Adjacency List of vertex " << i << ":\nHead";
		while(temp) {
			cout << "->" << temp->data ;
			temp = temp->next;
    }		
		cout << endl;
  }
}

void initialiseGraphList(graphList gList, graph g) {
	gList->n = g->n;
	gList->m = g->m;
	gList->arr = (AdjList*)malloc(gList->n * sizeof(struct AdjList));
 	for(int i=0; i<gList->n; i++) {
		gList->arr[i].head = NULL;
  }
}

list createNode(int key) {
	list temp = new AdjListNode;
	temp->data = key;
	temp->next = NULL;	
	return temp;
}

void fillGraphListWithMatrix(graphList gList, graph g) {
	 for(int i=0; i<(g->n); i++) {
		for(int j=0; j<=i/2; j++) {
			if(g->arr[i][j] == 1) {
				list temp = createNode(j);
				temp->next = gList->arr[i].head;
				gList->arr[i].head = temp;
				
 				// since it is an undirected graph
				
				temp = createNode(i);
				temp->next = gList->arr[j].head;
				gList->arr[j].head = temp;
				
			}
    }
   }
}

int main() { 
  int n, m;
	cout << "Enter number of vertices and edges:";
	cin >> n >> m;
	graph g = (graph)malloc(sizeof(node));
	initialiseGraph(g, n, m);
	fillMatrix(g);
	cout << "Adjacency Matrix:\n";
	printMatrix(g);
	
	graphList gList;
	gList = (graphList)malloc(sizeof(struct GraphNode));
	initialiseGraphList(gList, g);	
	fillGraphListWithMatrix(gList, g);
	printGraphList(gList);
	return 0;
}

/* Time Complexity O(n^2) where n is the number of vertices */
