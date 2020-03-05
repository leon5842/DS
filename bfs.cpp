#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool adj[9][9]; // 一張圖，資料結構為adjacency matrix。
bool visit[9];  // 記錄圖上的點是否遍歷過，有遍歷過為true。

void DFS()
{
	stack<int> q;
	for (int i=0; i<9; i++)
		visit[i] = false;

	visit[1] = true;
	visit[2] = true;
	visit[3] = true;
	visit[8] = true;

	for (int k=0; k<9; k++)
	{
		if (!visit[k])
		{
			q.push(k);
			visit[k] = true;

			while (!q.empty())
			{
				int i = q.top();
				q.pop();

				cout << "data = " << i << endl;

				for (int j = 0; j < 9; j++) 
				{
					if (adj[i][j] && !visit[j])
					{
						q.push(j);
						visit[j] = true;
					}
				}
			}
		}
	}
}




void BFS()
{
	queue<int> q;
	for (int i=0; i<9; i++)
		visit[i] = false;

	visit[1] = true;
	visit[2] = true;
	visit[3] = true;
	visit[8] = true;

	for (int k=0; k<9; k++)
	{
		if (!visit[k])
		{
			q.push(k);
			visit[k] = true;

			while (!q.empty())
			{
				int i = q.front();
				q.pop();

				cout << "data = " << i << endl;

				for (int j = 0; j < 9; j++) 
				{
					if (adj[i][j] && !visit[j])
					{
						q.push(j);
						visit[j] = true;
					}
				}
			}
		}
	}
}

int main()
{
	adj[0][4] = true;
	adj[0][7] = true;
	adj[4][6] = true;
	adj[5][7] = true;

	adj[4][0] = true;
	adj[7][0] = true;
	adj[7][5] = true;
	adj[6][4] = true;

	cout << "================= BFS ===============" << endl;
	BFS();
	cout << "================= DFS ===============" << endl;
	DFS();
}
