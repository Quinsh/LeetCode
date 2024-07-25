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
 * INTUITION: 2d DP. We can just iterate on the matrix. to do DP. think recursively.
 * 
 * TC: 
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int maxSquare = 0;
        for (int i = 0; i < matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i] - '0';
            maxSquare = maxSquare > dp[0][i] ? maxSquare : dp[0][i];
        }
        for (int i = 1; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxSquare = maxSquare > dp[i][0] ? maxSquare : dp[i][0];
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    maxSquare = maxSquare > dp[i][j] ? maxSquare : dp[i][j];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxSquare * maxSquare;
    }
};