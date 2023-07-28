// LeetCode 934: Shortest Bridge using BFS

class Solution
{
public:
    // these allow for traversing the graph
    vector<int> a = {0, 1, -1, 0};
    vector<int> b = {1, 0, 0, -1};

    // marks the first island as 2 instead of 1
    void dfs(vector<vector<int>> &grid, int x, int y, queue<pair<int, int>> &q)
    {
        int n = grid.size();
        // quits if outside the grid or island
        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1)
        {
            return;
        }
        grid[x][y] = 2;
        q.push({x, y});
        for (int i = 0; i < 4; i++)
        {
            int ax = x + a[i];
            int ay = y + b[i];
            dfs(grid, ax, ay, q);
        }
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool found = false;

        // Find the first island using DFS and mark it as '2'
        for (int i = 0; i < n && !found; i++)
        {
            for (int j = 0; j < n && !found; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, q);
                    // island 1 done
                    found = true;
                }
            }
        }

        // Perform BFS to expand the first island and find the shortest bridge
        int steps = 0;

        while (!q.empty())
        {

            int size = q.size();

            for (int k = 0; k < size; k++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int ax = x + a[i];
                    int ay = y + b[i];

                    if (ax >= 0 && ay >= 0 && ax < n && ay < n)
                    {
                        if (grid[ax][ay] == 1)
                        {
                            return steps; // Found the shortest bridge
                        }
                        // tries new path
                        if (grid[ax][ay] == 0)
                        {
                            grid[ax][ay] = 2;
                            q.push({ax, ay});
                        }
                    }
                }
            }
            steps++;
        }

        return -1; // If no bridge is found, return -1, this should not happen
    }
};
