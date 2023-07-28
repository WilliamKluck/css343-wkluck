// LeetCode 743: Network Delay Time using Dijkstra

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // creates adjacency list for ease
        vector<vector<pair<int, int>>> adjacencyList(n + 1);
        for (auto time : times)
        {
            adjacencyList[time[0]].push_back({time[1], time[2]});
        }

        // sets up dijkstra initialization
        // this is different because index 0 not a node
        vector<int> visited(n + 1, 0);
        visited[0] = 1;
        vector<int> previous(n + 1, 0);
        previous[k] = k;
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;

        // while there is an unvisited node
        while (find(visited.begin(), visited.end(), 0) != visited.end())
        {
            // finds the min distance node that is not visited
            int min = INT_MAX;
            int minIndex = 0;
            for (int i = 1; i < n + 1; i++)
            {
                if (min >= distance[i] && !visited[i])
                {
                    min = distance[i];
                    minIndex = i;
                }
            }

            // marks node as visited
            visited[minIndex] = 1;
            // updates distances for neighbors
            for (auto adjacent : adjacencyList[minIndex])
            {
                int neighbor = adjacent.first;
                if (!visited[neighbor])
                {
                    int weight = adjacent.second;
                    if (distance[minIndex] + weight < distance[neighbor])
                    {
                        previous[neighbor] = minIndex;
                    }
                    distance[neighbor] = std::min(distance[neighbor], distance[minIndex] + weight);
                }
            }
        }

        // returns the distance of the farthest node, if cannot be reached, return -1.
        return *max_element(distance.begin() + 1, distance.end()) == INT_MAX ? -1 : *max_element(distance.begin() + 1, distance.end());
    }
};
