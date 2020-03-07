/*
 *  Leetcode test for islands jump & counting
 *
 */

void DFS(int r, int c, vector<vector<char>> &grid)
{
	int nr = grid.size();
	int nc = grid[0].size();

	if (r >= 0 && r < nr && c >=0 && c < nc && grid[r][c] == '1')
	{
		grid[r][c] = '0';
		DFS(r + 1, c, grid);
		DFS(r - 1, c, grid);
		DFS(r, c + 1, grid);
		DFS(r, c - 1, grid);
	}
}

int countIslands(vector<vector<char>> &grid)
{
	int islands = 0;
	int nc, nr;

	if (grid.empty())
		return 0;

	/* get column */
	nc = grid[0].size();
	/* get row */
	nr = grid.size();

	for (int r = 0; r < nr; r++)
		for (int c = 0; c < nc; c++)
		{
			if (grid[r][c] == '1') 
			{
				islands++;
				DFS(r,c, grid);
			}
		}

	return islands;
}



