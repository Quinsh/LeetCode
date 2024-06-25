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
 * DATE: 2024.06.24
 * INTUITION: we could use maxheap and do a O(mn logk) solution, but there is a better solution. 
 * Start a minheap with elements from the first column. Then for k times, pop and the top and push the next value from the same row that you popped.
 * 
 * TC: O((m+k)logk) - O(mlogk) for initializing the heap with first column, O(klogk) for iterating.
 * SC: O(k) - the minheap used is of size k
 * 
 * TOIMPROVE: there is also some binary search solution. Understand this approach.
*/
class Solution_378 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();

        // Define the min-heap using the custom comparator
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        // Initialize the min-heap with the first element of each row
        for (int r = 0; r < m; ++r) {
            minHeap.push({matrix[r][0], r, 0});
        }

        // Extract the smallest element k times
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            auto top = minHeap.top(); minHeap.pop();
            int r = top[1], c = top[2];
            ans = top[0];
            if (c + 1 < n) {
                minHeap.push({matrix[r][c + 1], r, c + 1});
            }
        }
        return ans;
    }
};
