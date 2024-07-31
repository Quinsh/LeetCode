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
 * DATE: 2024.07.25
 * INTUITION: state: day(i), job(j)
 * dp[i, 0] = min job difficulty at day[i]. for the first day, j can't be 0
 * then, dp[i, j] = max(dp[i+1][j+1], dp[i+1][j+2],... till where `j` can be partitioned correctly)
 * j needs to be partitioned in a way that future DPs has at least one jobs per day.
 * 
 * TC: O(D*N^2)
 * SC: O(D*N^2)
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    int d, n;
    vector<int> jobDifficulty;
    vector<vector<int>> cache;
public:
    int minDifficulty(vector<int>& _jobDifficulty, int _d) {
        jobDifficulty = _jobDifficulty;
        n = _jobDifficulty.size();
        d = _d;
        if (d > n) return -1;
        cache.resize(d, vector<int>(n, -1));
        return dp(0, 0);
    }

    int dp(int i, int j) {
        // after the last day
        if (i==d) return 0;
        // cache:
        if (cache[i][j] != -1) {
            return cache[i][j];
        }
        if (i+1 == d) {
            int mael = *max_element(jobDifficulty.begin()+j, jobDifficulty.end());
            cache[i][j] = mael;
            return mael;
        }

        int min = 1e9;
        int end = n-d+i+2; // needs to guarantee that further DPs have at least one job for each day.
        // came up with this by doing j+1 + ((n-j)-(d-i)+1) = n-d+i+2
        int maxjobdif = -1;
        for (int k = j+1; k < end; k++) {
            maxjobdif = jobDifficulty[k-1] > maxjobdif ? jobDifficulty[k-1] : maxjobdif;
            int DP = maxjobdif + dp(i+1, k);
            min = min < DP ? min : DP;
        }
        cache[i][j] = min;
        return min;
    }
};