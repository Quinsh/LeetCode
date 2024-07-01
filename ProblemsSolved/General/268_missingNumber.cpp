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
 * DATE: 2024.06.28
 * INTUITION: just subtract the sum from the gauss sum of 0 to max
 * 
 * TC: O(n) - array iteration
 * SC: O(1) - no special ds used
 * 
 * TOIMPROVE: nothigm
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int gaussSum = (nums.size()+1) * double(nums.size())/2;

        int sum = accumulate(nums.begin(), nums.end(), 0);

        return gaussSum - sum;
    }
};