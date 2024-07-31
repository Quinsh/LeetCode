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
 * DATE: 2024.07.26
 * INTUITION: let's use DP just to practice DP. But there are better ways to solve it.
 * Even brute force is better than DP here.
 * 
 * TC: O(n^2)
 * SC: O(n)
 * 
 * TOIMPROVE: TLE.. it'd pass if we have done iterative way idk..
 */
class Solution {
private:
    vector<int> prices;
    vector<int> cache;
public:
    int maxProfit(vector<int>& _prices) {
        cache.resize(_prices.size()+1, -1);
        prices=_prices;
        return dp(prices.size()-1);
    }
    
    int dp(int i) {
        if (cache[i] == -1) {
            if (i == 0) return 0;
            
            int maxprofit = 0;
            for (int k = 0; k < i; k++) {
                maxprofit = max(maxprofit, dp(k)); // dp(k) means not buying
                maxprofit = max(maxprofit, dp(k) + prices[i] - prices[k]); // dp(k) + (prices[i]-prices[k]) means buying at day k and selling at i.
            }
            cache[i] = maxprofit;
        }
        return cache[i];
    }
};
// one pass method
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int csum = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                csum += prices[i]-prices[i-1];
            }
        }
    }
};

