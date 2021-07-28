
void Graph:BFS(int vertex)
{
	queue<int> q;
	list<int> adjList;
	list<int>::iterator i;
	
	visited[vertex] = true;
	q.push(vertex);

	while (!q.empty())
	{
		int cur = q.fron();
		q.pop();

		adjList = adjLists[cur];
		
		for (i = adjList.begin(); i != adjList.end(); i++)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}

void Graph::DFS(int vertex)
{
	visited[vertex] = true;
	list<int> adjList = adjLists[vertex];
	list<int>::iterator it;

	for (it = adjList.begin(); it != adjList.end(); it++)
		if (!visited[*it])
			DFS(*it);
}


void Graph::DFS(int vertex)
{
	visited[vertex] = true;
	list<int> adjList = adjLists[vertex];
	
	cout << vertex << endl;
	
	for (each adj node)
	{
		if (!visited[i])
			DFS(i);
	}
}

void Graph:BFS(int vertex)
{
	queue<int> q;
	list<int> adjList;
	list<int>::iterator it;

	visited[vertex] = true;
	q.push(vertex);
	
	while (q not empty)
	{
		int cur = q.front();
		q.pop();
		adjList = adjLists[cur];
		cout << cur << endl;

		for (each adj node with cur)
		{
			if(!visited[i])
			{
				visited[i] = true;
				q.push[i];
			}
		}
	}


}


void BST::delete_node(TreeNode* &fake_root, int key)
{
	TreeNode *cur;

	if (fake_root->val < key)
		delete_node(fake_root->right, key);
	else if (fake_root->val > key)
		delete_node(fake_root->left, key);
	else /* hit */
	{
		if (fake_root->left && fake_root->right both null)
		{
			delete fake_root;
			fake_root = NULL;
		} 
		else if (fake_root->left && fake_root->right) {
			TreeNode *successor = leftMost(fake_root->right);
			fake_root->val = successor->val;
			delete_node(successor, successor->val);
		} else {
			TreeNode *tmp = fake_root->left ? :fake_root->left : fake_root->r;
			TreeNode *del_node = fake_root;
			fake_root = tmp;
			delete del_node;
		}
	}
}

