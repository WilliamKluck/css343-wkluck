// LeetCode 79: Word Search using DFS

class Solution
{
public:
    vector<int> a = {0, 1, -1, 0};
    vector<int> b = {1, 0, 0, -1};

    bool dfs(const vector<vector<char>> &board, vector<vector<int>> &visited, int x, int y, const string &word, int pos)
    {
        if (pos == word.length())
        {
            return true; // Entire word has been found
        }

        // mark as visited
        visited[x][y] = 1;

        // check neighbors
        for (int i = 0; i < 4; i++)
        {
            int ax = x + a[i];
            int ay = y + b[i];
            // if in board and not visited and next letter
            if (ax >= 0 && ay >= 0 && ax < board.size() && ay < board[0].size() && !visited[ax][ay] && board[ax][ay] == word[pos])
            {
                if (dfs(board, visited, ax, ay, word, pos + 1))
                {
                    return true;
                }
            }
        }

        visited[x][y] = 0; // Backtrack
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        // define the size of the board
        int n = board.size();
        int m = board[0].size();
        // initialize the visited array
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // find the first letter
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0] && dfs(board, visited, i, j, word, 1))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
