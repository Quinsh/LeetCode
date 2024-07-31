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
 * DATE: 2024.07.28
 * INTUITION: we start the dp at dp(0,0,0). Think like the LCS (Largest Common Substring) question. We perform an action and pass the smaller problem to the recursion.
 * we can do an action at ith day and figure out the optimal for the rest. (not go from back to front).
 * 
 * TC: 
 * SC: 
 * 
 * TOIMPROVE: 
 */
#define donothing dp(i+1, k, h)// just go to the next case holding the stock we have bought before
#define buy -prices[i] + dp(i+1, k, 1) // buy at current price (so we just diminsh the price from the total value we return)
#define sell prices[i] + dp(i+1, k-1, 0) // sell at current price

class Solution {
private:
    int n; // n days
    vector<int> prices;
    vector<vector<vector<int>>> cache;
public:
    int maxProfit(int k, vector<int>& _prices) {
        prices = _prices;
        n = prices.size();
        cache.resize(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return dp(0, k, 0);
    }
    
    int dp(int i, int k, int h) { // i'th day, k trading left, h is 0 if we're not holding some stock, 1 if we are holding some stock.
        if (cache[i][k][h] == -1) {
            // base case
            if (k == 0 || i == n) return 0;
            
            // recursive case
            if (h == 0) // we don't hold any stock we can choose to buy or just not do anything.
                cache[i][k][h] = max(donothing, buy);
            else        // we hold some stock, so we can choose to sell it at current price or don't do anything and pass to next price.
                cache[i][k][h] = max(donothing, sell);
        }
        return cache[i][k][h];
    }
};