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
 * INTUITION: my thought process: O(logn) approach would be binary search. --> to start with, where do we search from? input array? array of elements missing? (<- this would take O(n) to make so NO)
 * --> if we binsearch from input array, what is the info that we can obtain in O(1) each iteration? --> Each iteration we can know how many elements are missing up to that point (by doing input[i] - i -1)
 * --> Ok this is enough.
 * 
 * TC: O(logn)
 * SC: O(1)
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size()-1, mid, missing;
        while (l < r) { // stops with the l == r == the rightmost bound
            mid = l + (r-l)/2;
            missing = arr[mid] - mid -1;
            if (missing < k)
                l = mid+1;
            else // if missing >= k
                r = mid;
        }

        if (missing >= k) 
            return arr[l] - (missing-k) - 1;
        else
            return arr[l] + (k-missing);
    }
};