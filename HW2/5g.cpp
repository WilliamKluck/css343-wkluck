/* utilized online resources https://www.geeksforgeeks.org/implement-min-heap-using-stl/
& https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/# */

#include <math.h>

class Heap {
private:
    // Comparison struct for priority queue
    struct ComparePoints {
        bool operator()(const vector<int>& p1, const vector<int>& p2) {
            // Calculate distances from the origin
            double dist1 = sqrt(pow(p1[0] - 0, 2.0) + pow(p1[1] - 0, 2.0));
            double dist2 = sqrt(pow(p2[0] - 0, 2.0) + pow(p2[1] - 0, 2.0));
            // Reverse comparison for max heap (larger distances considered smaller)
            return dist1 < dist2;
        }
    };

    priority_queue<vector<int>, vector<vector<int>>, ComparePoints> points;
    int itemCount;
    int maxItems;

public:
    Heap(int k) : itemCount(0), maxItems(k) {}

    int size() const { return itemCount; };

    void insert(const vector<int>& p) {
        if (itemCount < maxItems) {
            // If heap is not full, insert point
            itemCount++;
            points.push(p);
        } else if (ComparePoints()(p, points.top())) {
            // If point is closer than maximum distance in heap, replace the maximum distance point
            points.pop();
            points.push(p);
        }
    }

    vector<vector<int>> getPoints() const {
        vector<vector<int>> result;
        priority_queue<vector<int>, vector<vector<int>>, ComparePoints> pq = points;

        while (!pq.empty()) {
            // Retrieve points from priority queue and store in result vector
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Use k as the maxItems parameter for the Heap constructor
        Heap maxHeap(k); 
        vector<vector<int>> result;

        // Insert points into the maxHeap
        for (const vector<int>& point : points) {
            maxHeap.insert(point);
        }

        // Retrieve k closest points from the maxHeap
        return maxHeap.getPoints(); 
    }
};
