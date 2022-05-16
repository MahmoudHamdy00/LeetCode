class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
        int dy[] = {1, -1, 0, -1, 1, 0, -1, 1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        int dep = 0;
        do
        {
            ++dep;
            int sz = q.size();
            while (sz--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (grid[x][y])
                    continue;
                grid[x][y] = 1;
                if (x == grid.size() - 1 && y == grid.size() - 1)
                    return dep;
                for (int i = 0; i <8; ++i)
                {
                    int to_x = x + dx[i], to_y = y + dy[i];
                    if (to_x >= grid.size() || to_x < 0 || to_y >= grid[0].size() || to_y < 0)
                        continue;
                    q.push({to_x, to_y});
                }
            }

        } while (!q.empty());
        return -1;
    }
};