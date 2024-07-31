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
 * INTUITION: 1d DP Problem.
 * 
 * TC: O(n*s)
 * SC: O(n*s)
 * 
 * TOIMPROVE: use tabulation
 */
class Solution {
private:
    vector<int> coins;
    vector<int> cache;
public:
    int coinChange(vector<int>& _coins, int amount) {
        coins = _coins;
        cache.resize(max(amount, *max_element(coins.begin(),coins.end()))+1, -1);
        cache[0] = 0;
        for (const auto &coin:coins) cache[coin] = 1;
        return dp(amount);
    }
    int dp(int n) {
        if (cache[n] == -1) {
            int mincoins = 1e9;
            for (const auto &coin : coins) {
                if (n-coin > 0) {
                    int DP = dp(n-coin);
                    if (DP == -1) continue;
                    mincoins = min(mincoins, 1 + DP);
                }
            }
            if (mincoins == int(1e9)) cache[n] = -1;
            else cache[n] = mincoins;
        }

        return cache[n];
    }
};

// using tabulation. and with cleaner logic:
class Solution {
private:
    vector<int> coins;
public:
    int coinChange(vector<int>& _coins, int amount) {
        coins = _coins;
        vector<int> dp; dp.resize(amount+1, int(1e9));
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (const auto &coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], 1+dp[i-coin]);
                }
            }
        }
        return dp[amount];
    }
};