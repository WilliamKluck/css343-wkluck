#include <math.h>

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // stores all distances of points from origin
        multimap<double, vector<int>> compareChart;
        // stores the smallest distances
        vector<vector<int>> result;
        if (k == 0)
        {
            return result;
        }

        // adds distances to compareChart
        for (const vector<int> &point : points)
        {
            double distance = sqrt(pow(point[0] - 0, 2.0) + pow(point[1] - 0, 2.0));
            compareChart.emplace(distance, point);
        }

        // grabs the first k points in compareChart (because maps are sorted in increasing order)
        for (const auto &pair : compareChart)
        {
            // adds to result
            result.push_back(pair.second);
            // ensures only k points are stored
            if (result.size() >= k)
            {
                return result;
            }
        }
        return result;
    }
};