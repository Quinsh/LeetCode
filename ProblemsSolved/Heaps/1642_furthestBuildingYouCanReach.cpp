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
 * INTUITION: I should use ladder for the highest building, and bricks to the smallest buildings.
 * make a heap with of pair<height difference, height accumulated>. 
 * If, by subtracting that biggest height difference, the rest of cumulative height can be climbed, we can climb up to that point.
 * 
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
    }
};