// LeetCode 210: Course Schedule II using Topological Sort
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // create the course Adjacency List
        vector<vector<int>> cAL(numCourses);
        for (vector<int> prereq : prerequisites)
        {
            cAL[prereq[1]].push_back(prereq[0]);
        }

        // mark all vertices as not visited
        vector<int> visited(numCourses, 0);
        stack<int> order;
        for (int vertice = 0; vertice < numCourses; vertice++)
        {
            if (visited[vertice] != 2)
            { // if its not black
                if (dfs(vertice, cAL, visited, order) == 1)
                {
                    return {}; // if cycle return empty
                };
            }
        }
        vector<int> solution;
        while (!order.empty())
        {
            solution.push_back(order.top());
            order.pop();
        }
        return solution;
    }

    int dfs(int v, const vector<vector<int>> &cAL, vector<int> &visited, stack<int> &order)
    {
        // if black already visited
        if (visited[v] == 2)
        {
            return 2;
        }
        // if grey cycle detected
        if (visited[v] == 1)
        {
            return 1;
        }
        // mark vertice as visiting (grey)
        visited[v] = 1;
        // all adjacent nodes to v
        for (int w : cAL[v])
        {
            if (visited[w] != 2)
            {
                if (dfs(w, cAL, visited, order) == 1)
                {
                    return 1;
                }
            }
        }
        // mark vertice as visited (black)
        visited[v] = 2;
        order.push(v);
        return 2;
    }
};