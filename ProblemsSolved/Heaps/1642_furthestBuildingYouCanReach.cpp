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
 * DATE: 2024.06.26
 * INTUITION: I should use ladder for the highest building, and bricks to the smallest buildings.
 * make a vector of pair<height difference, cumulative height>.
 * iterate buliding, and if cumulative height is > than bricks, use a ladder for the tallest building so far, and proceed to iterate with the saved bricks.
 * If both bricks and ladder run out, we are done.
 * Actually, we don't even need a pair structure.
 * 
 * TC: O(NlogN) <-- O(N) + O(NlogN) - k are the ladders. O(N) for building vectors and heaps. NlogN for pushing and popping 
 * SC: O(N) - O(N) for vector, O(N) for heap
 * 
 * TOIMPROVE: learn the binary search method. and how to optimize this solution.
*/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // store height difference
        vector<int> heightdiff; heightdiff.resize(heights.size());

        for (int i = 1; i < heights.size(); i++) {
            heightdiff[i] = heights[i] - heights[i-1];
            if (heightdiff[i] < 0) heightdiff[i] = 0;
        }
        heightdiff[0] = 0;

        priority_queue<int> maxheap; // 0 0 5 0 3 5 0 
        int sumHeightDiffs = 0;
        int ans = -1;
        int s = heightdiff.size();
        for (int i = 0; i < s; i++) {

            sumHeightDiffs += heightdiff[i];
            maxheap.push(heightdiff[i]);

            if (sumHeightDiffs > bricks) {
                if (ladders) {
                    ladders--;
                    sumHeightDiffs -= maxheap.top(); maxheap.pop();
                }
                else {
                    break;
                }
            }
            if (sumHeightDiffs > bricks) {
                break;
            }

            ans = i;
        }
        return ans;
    }
};