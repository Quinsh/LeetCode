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
 * INTUITION: do a O(n) checking for each binsearch iteration --> O(nlogn) approach.
 * binary search within [1, piles.maxElement]
 * 
 * TC: O(nlogn) - O(n) check for each search iteration
 * SC: O(1) - no additional ds
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = piles.size(), r = *max_element(piles.begin(), piles.end()), mid;
        
        while (l < r) {
            mid = l + (r-l)/2;
            if (canEat(piles, mid, h))
                r = mid;
            else
                l = mid + 1;
        }
        // at the end of the loop, l == r == smallest k that works.

        return l;
    }

    bool canEat(vector<int> piles, int k, int h) {
        int cnt = 0;
        for (auto p : piles) {
            while (p) {
                if (p <= k) p = 0;
                else p -= k;
                cnt++;
            }
        }
        if (cnt > h) return false;
        else return true;
    }
};