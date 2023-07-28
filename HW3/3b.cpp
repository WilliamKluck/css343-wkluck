// LeetCode 133: Clone Graph using BFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *bfs(Node *node, unordered_map<Node *, Node *> &visited)
    {
        // if Node is already visited, return the visited node
        if (visited.find(node) != visited.end())
        {
            return visited[node];
        }

        // create clone
        Node *clone = new Node(node->val);
        // mark as visited
        visited[node] = clone;

        // clone neighbors and mark as neighbors
        for (Node *neighbor : node->neighbors)
        {
            clone->neighbors.push_back(bfs(neighbor, visited));
        }

        return clone;
    }

    Node *cloneGraph(Node *node)
    {
        // if doesn't exist return nullptr
        if (!node)
        {
            return nullptr;
        }

        // tracking visited nodes
        unordered_map<Node *, Node *> visited;
        return bfs(node, visited);
    }
};