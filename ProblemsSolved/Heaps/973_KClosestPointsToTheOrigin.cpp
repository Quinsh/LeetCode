#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

/**
 * DATE: 2024.06.25
 * INTUITION: calulate vector of pair<index, distance> then, make a minheap of it. pop the k elements from the heap
 * 
 * TC: O(N + KlogN) - O(N) to calculate the distance, O(N) to make the minheap, O(KlogN) to pop from the heap.
 * SC: O(N) - heap and vectors depend on the length of points vector
 * 
 * TOIMPROVE: there is a binary search, and quickselect algorithm that can be used for this. Understand this concept.
*/
class Solution_973 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, double>> distancemapping;
        int index = 0;
        for (const auto &point : points) {
            double dist = sqrt(point[0]*point[0] + point[1]*point[1]);
            distancemapping.emplace_back(index++, dist);
        }

        auto cmp = [](const pair<int, double> &p1, const pair<int, double>  &p2) {
            return p1.second > p2.second;
        };

        priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(cmp)> minheap(cmp, distancemapping);

        vector<vector<int>> ans;

        for (int i = 0; i < k; i++) {
            auto top = minheap.top(); minheap.pop();
            int ind = top.first;
            ans.push_back(points[ind]);
        }  

        return ans;
    }
};