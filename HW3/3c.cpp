// LeetCode 200: Number Of Islands using DFS

class Solution
{
public:
    // defines directions
    vector<int> a = {0, 1, -1, 0};
    vector<int> b = {1, 0, 0, -1};

    void dfs(const vector<vector<char>> &grid, vector<vector<int>> &visited, int x, int y, int &flag)
    {
        // marks as visited
        visited[x][y] = 1;

        // marks when not part of island
        if (grid[x][y] != '1')
        {
            flag = 0;
        }
        // tries each direction one at a time
        for (int i = 0; i < 4; i++)
        {
            int ax = x + a[i];
            int ay = y + b[i];
            // if within grid and not visited, and part of island
            if (ax >= 0 && ay >= 0 && ax < grid.size() && ay < grid[0].size() && grid[ax][ay] == '1' && !visited[ax][ay])
            {
                // explore island
                dfs(grid, visited, ax, ay, flag);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        // easy dimensions
        int n = grid.size();
        int m = grid[0].size();

        // initalize grid spaces as not visited
        vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // when not visited and an island, explore island
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    int flag = 1;
                    dfs(grid, visited, i, j, flag);
                    // when an island is complete, count it
                    if (flag)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};