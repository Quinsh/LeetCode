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
 * INTUITION: 
 * 
 * TC: O(N)
 * SC: O(N)
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    vector<vector<int>> cache;
    vector<int> prices;

public:
    int maxProfit(vector<int>& _prices) {
        cache.resize(_prices.size()+1, vector<int>(2, -1));
        prices = _prices;
        return dp(0, 0);
    }
    int dp(int i, int h) {
        if (i >= prices.size()) return 0;
        
        if (cache[i][h] == -1) {
            if (h == 1)
                cache[i][h] = max(dp(i+1,h), prices[i] + dp(i+2, 0));
            else
                cache[i][h] = max(dp(i+1,h), -prices[i] + dp(i+1, 1));
        }

        return cache[i][h];
    }
};