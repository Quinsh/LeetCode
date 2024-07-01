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
 * DATE: 2024.06.30
 * INTUITION: sort the array. Then, start two pointers. Left pointer indicates the first number of the pair, and right pointer indicates the maximum second element.
 * add the range btw them to the answer each iteration.
 * 
 * TC: O(nlogn) - bound of sorting the array
 * SC: O(1)
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size()-1, ans = 0;
        
        while (1) {
            while (nums[l] + nums[r] >= target && r) r--;
            if (l >= r) break;

            ans += r-l;
            l++;
        }
        return ans;
    }
};