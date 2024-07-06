#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define btoe(x) (x).begin(), (x).end()
#define pb push_back

const int INF = 1e9;
const int MOD = 1e9 + 7;

/**
 * DATE: 2024.07.04
 * INTUITION: how would we verify number of pairs whose sum is <= X? (if we
 * could do this we can use binary search) given [1 3 1] --sort-> [1 1 3], then
 * we need to know that we have 0, 2, 2 of pair differences.
 *
 * Given X=2, we have 3 pairs:  X=2 --> so 3-1. r-l+1 has length of 3, so 2C3
 * = 3. So we have 3 possible pair. The problem is that this is O(N) checking
 * cuz it's two pointers. So overall algorithm would be O(NlogN). Well... but
 * it's alrdy NlogN for sorting so I guess it shouldn't matter?
 *
 * Ok. No this checking doesn't work.
 *
 * Idk. The definition of `pairs` is very bad here. I'll just see the solution
 *
 *
 * TC: O(NlogN)
 * SC: O(1)
 *
 * TOIMPROVE:
 */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(btoe(nums));
        int maxpair = nums[nums.size() - 1] - nums[0];
        int l = 0, r = maxpair, mid = 0;

        while (l < r) {
            mid = l + (r - l) / 2;
            int pairsToTheLeft = pairsLessorEqThanX(nums, mid);

            if (pairsToTheLeft < k)
                l = mid + 1;
            else if (pairsToTheLeft >= k)
                r = mid;
        }
        return l;
    }

    int pairsLessorEqThanX(vector<int>& nums, int X) {
        int l = 0, r = 0;
        int n = nums.size(), cnt = 0;

        while (l < n) {
            while (r < n && nums[r] - nums[l] <= X) {
                r++;
            }
            cnt += r - l - 1;
            l++;
        }
        return cnt;
    }
};