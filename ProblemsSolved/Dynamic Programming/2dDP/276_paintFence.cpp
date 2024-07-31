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
 * INTUITION: let's use a variable h to indicate how many consecutive same color we are using at current fence.
 * 
 * TC: 
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    vector<vector<int>> cache;
    int n, k;
public:
    int numWays(int _n, int _k) {
        cache.resize(n+1, vector<int>(2, -1));
        n = _n; k = _k;
        return dp(0, 0);
    }
    
    int dp(int i, int h) {
        if (i == n) return 1;
        if (cache[i][h] == -1) {
            if (h == 1)
                cache[i][h] = (k-1) * dp(i+1, 0);
            else
                cache[i][h] = k * dp(i+1, h+1);
        }
        return cache[i][h];
    }
};