#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * DATE: 2024.06.20
 * INTUITION: This one seems easy: brute force method would work. Just do DFS and count what results in the target. So the time complexity would be maximum 2^20.
 * We can either use stack or do recursion. If we use recursion, space complexity will increase cuz we are creating new array everytime, but since array size is 20 at max,
 * doesn't matter that much. I'll do recursion.

 * TC: O(2^N)
 * SC: 
 * 
 * TOIMPROVE: 
*/
class Solution494 {
private:
    vector<vector<int>> memo;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(nums, 0, target, 0);
    }
    int rec(vector<int>& nums, int i, int target, int sum) {
        
        if (i == nums.size()) 
            return target == sum;

        vector<int> newnums = nums;
        
        return rec(newnums, i+1, target, sum + nums[i]) + rec(newnums, i+1, target, sum - nums[i]);
    }
};