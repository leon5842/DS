#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int numVertices;
	list<int> *adjLists;
	bool *visited;

	public:
	Graph(int V);
	void addEdge(int src, int dest);
	void DFS(int vertex);
};

Graph::Graph(int vertices)
{
	numVertices = vertices;
	adjLists = new list<int>[vertices];
	visited = new bool[vertices];
}

void Graph::addEdge(int src, int dest)
{
	adjLists[src].push_front(dest);
}

void Graph::DFS(int vertex)
{
	visited[vertex] = true;
	list<int> adjList = adjLists[vertex];

	cout << vertex << " ";

	list<int>::iterator i;

	for(i = adjList.begin(); i != adjList.end(); ++i)
		if(!visited[*i])
			DFS(*i);
}

int main()
{
	Graph g(8);
#if 0 
	bool **visited;
	
	visited = new bool*[10];
	
	for (int i = 0; i < 10; i ++)
		visited[i] = (bool*) new bool[10];

		cout << "HHHHHHHHHHH";
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			cout << " i = " << i << "j = "<<j;
			visited[i][j] = false;
		}
#endif
#if 1
	g.addEdge(0, 4);
	g.addEdge(0, 7);
	g.addEdge(4, 6);
	g.addEdge(7, 5);

	g.DFS(0);
#endif
	return 0;
}
