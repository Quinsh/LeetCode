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
 * INTUITION: basic DP
 * 
 * TC: O(N)
 * SC: O(N)
 * 
 * TOIMPROVE: optimize to use O(1) space w iteration. 
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 1) return cost[0];
        if (cost.size() == 2) return min(cost[0], cost[1]);

        vector<int> dp; dp.resize(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = cost[i] + min(dp[i-2], dp[i-1]);
        }
        return min(dp[dp.size()-1], dp[dp.size()-2]);
    }
};