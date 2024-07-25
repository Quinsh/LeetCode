#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <iostream>

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
 * DATE: 2024.07.24
 * INTUITION: 3d dynamic programming that can be solved with 2d dynamic programming.
 * this was challenging. I had to see the solution.
 * 
 * TC: O(M^2)
 * SC: O(M^2)
 * 
 * TOIMPROVE: try to implement bottom up way.
 */
class Solution {
private:
    vector<int> nums, multipliers;
    vector<vector<int>> cache;
public:
    int maximumScore(vector<int>& _nums, vector<int>& _multipliers) {
        nums = _nums;
        multipliers = _multipliers;
        cache.resize(multipliers.size(), vector<int>(multipliers.size()));
        return dp(0, 0);
    }

    int dp(int i, int l) {
        if (i == multipliers.size()) return 0;
        if (cache[i][l] == 0) {
            cache[i][l] = max(nums[l]*multipliers[i] + dp(i+1, l+1),
                            nums[nums.size()-1 -(i-l)]*multipliers[i] + dp(i+1, l));
        };
        return cache[i][l]; 
    }
};