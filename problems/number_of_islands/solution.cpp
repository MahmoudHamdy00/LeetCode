class Solution {
public:
    const int dx[4] = { 1, 0, -1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };
	int n, m, cnt = 0;
    vector<vector<char>> g;
	bool valid(int i, int j)
	{
		return (i < n&& i >= 0 && j < m&& j >= 0);
	}
	void floodFill(int i = 0, int j = 0)
	{
		if ( !valid(i, j)||g[i][j] == '0'  )
			return;
		cnt++;
		g[i][j] = '0';
		for (int idx = 0; idx < 4; idx++)
			floodFill(i + dx[idx], j + dy[idx]);
	}
	int cntComponant(int i = 0, int j = 0)
	{
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cnt = 0;
				floodFill(i, j);
				if (cnt)
					c++;
			}
		}
		return c;
	}
	int numIslands(vector<vector<char>>& grid) {
        g=grid;
        n=grid.size();
        m=0;
        if(n)
        m=(int)grid[0].size();

        return cntComponant();
	}
};