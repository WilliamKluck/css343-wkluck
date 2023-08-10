// LeetCode 1584: Min Cost to Connect All Points using Prim's Algorithm

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numPoints = points.size(); //saves size for expediency
        vector<int> visited(numPoints, 0); //track visited nodes
        vector<int> minCost(numPoints, INT_MAX); //track minimum cost to connect each point
        int totalCost = 0; //track total minimum cost

        vector<vector<pair<int,int>>> adjList(numPoints); //creates adjacency list

        for(int i = 0; i < numPoints; i++) { //fills adjacency list using Manhattan distance for weights
            for(int j = i+1; j < numPoints; j++) { //i+1 cuts runtime in half
                int dist = abs(points[i][0]- points[j][0]) + abs(points[i][1] - points[j][1]); //saves distance for expendiency
                adjList[i].push_back({j, dist}); 
                adjList[j].push_back({i, dist});
            }
        }

        minCost[0] = 0; //initialize with first point

        //Prim's Algorithm
        for(int i = 0; i < numPoints; i++) {
            int currentPoint = -1; //no current point
            for(int j = 0; j < numPoints; j++) {
                if(!visited[j] && (currentPoint == -1 || minCost[j] < minCost[currentPoint])) { 
                    currentPoint = j; 
                }
            }
            visited[currentPoint] = 1; //mark point as visited
            totalCost += minCost[currentPoint]; //add to total cost

            //update minimum cost for adjacent points
            for(const auto& edge : adjList[currentPoint]) {
                int adjacentPoint = edge.first;
                int cost = edge.second;
                minCost[adjacentPoint] = min(minCost[adjacentPoint], cost);
            }
        }

        return totalCost;
    }
};
