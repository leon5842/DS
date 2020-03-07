#include <iostream>
#include <cstring>
#include <list>
#include <queue>
using namespace std;


class Graph
{
public:
		Graph(int vertices);
		void addEdge(int src, int dst);
		void DFS(int vertex);
		void BFS(int vertex);
		void Reset();

private:
		list<int> *adjLists;
		int numVertices;
		bool *visited;
};

Graph::Graph(int vertices)
{
	adjLists = new list<int>[vertices];
	numVertices = vertices;
	visited = new bool[vertices];
	cout << "constructor finished" << endl;
}

void Graph::addEdge(int src, int dst)
{
	adjLists[src].push_back(dst);
}

void Graph::DFS(int vertex)
{
	/* protect null access */
	if (visited == NULL)
		return;

	list<int> adjList = adjLists[vertex];
	visited[vertex] = true;

	cout << vertex << endl;
	list<int>::iterator it;
	for (it = adjList.begin(); it != adjList.end(); it++)
		if (!visited[*it])
				DFS(*it);
}

void Graph::BFS(int vertex)
{
	list<int> adjList;
	queue<int> q;

	q.push(vertex);
	visited[vertex] = true;
	
	list<int>::iterator it;

	while (!q.empty())
	{
		int val = q.front();
		cout << val << endl;
		q.pop();

		adjList = adjLists[val];

		for (it = adjList.begin(); it != adjList.end(); it++)
		{
			if (!visited[*it])
			{
				q.push(*it);
				visited[*it] = true;
			}
		}

	}
}

void Graph::Reset()
{
	printf("hahahahaha reset \n");
	memset(visited, 0, sizeof(bool) * numVertices);
}

int main()
{
	Graph g(8);

	g.addEdge(0, 4);
	g.addEdge(0, 7);
	g.addEdge(4, 6);
	g.addEdge(7, 5);

	g.DFS(0);
	g.Reset();
	g.BFS(0);


	return 0;
}
