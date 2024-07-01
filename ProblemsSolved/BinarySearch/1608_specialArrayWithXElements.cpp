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
 * DATE: 2024.06.29
 * INTUITION: "It can be proven that if nums is special, the value for x is unique." This is critical info.
 * 
 * if X doesn't have X elements >= than itself, numbers bigger than X, say Y, will not have Y elements >= than itself (so they shouldn't be considered)
 * if X has more more than X elements >= than itself, numbers smaller than X, say Y, will not have Y elements >= than itself (but more than Y. so they shouldn't be considered)
 * 
 * this implies binary search!!
 * 
 * but, for each binary search 
 * 
 * TC: O(N+logN) - O(N) for making the `biggerThan` array, O(logN) for performing binary search;
 * SC: O(N)
 * 
 * TOIMPROVE: actually, we don't even need to make the biggerThan array up to maxnum. We can just make until the size of the num. And when populating the biggerThan array, if n > size, we just increment the last index of biggerThan.
*/
class Solution {
public:
    int specialArray(vector<int>& nums) {
        // make the `biggerThan` array, which tells you how many elements are bigger.
        int size = nums.size();
        vector<int> biggerThan; biggerThan.resize(size+1);
        for (auto &n : nums)
            biggerThan[n]++;
        for (int i = biggerThan.size()-2; i >= 0; i--)
            biggerThan[i] += biggerThan[i+1];

        // binary search
        int l = 0, r = size, mid;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (biggerThan[mid] == mid) { // then this is the `X` number
                return mid;
            }
            else if (biggerThan[mid] > mid) { // numbers smaller than mid can't be `X`
                l = mid+1;
            }
            else if (biggerThan[mid] < mid) { // numbers bigger than mid can't be `X`
                r = mid-1;
            }
        }
        // if l > r, we couln't find the `X`.
        return -1;
    }
};
