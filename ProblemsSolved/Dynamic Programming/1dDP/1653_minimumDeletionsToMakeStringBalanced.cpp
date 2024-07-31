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
 * DATE: 2024.07.31
 * INTUITION: 
 * 
 * TC: 
 * SC: 
 * 
 * TOIMPROVE: 
 */

// my 2d DP solution that works for string of all characters not only for 'a' and 'b'.
// but it's giving Memory Limit Exceeded...
class Solution {
private:
    int len;
    string s;
    vector<vector<int>> cache;
public:
    int minimumDeletions(string _s) {
        cache.resize(_s.size(), vector<int>(_s.size(), -1));
        s = _s;
        len = _s.size();
        return dp(0, -1);
    }

    int dp(int i, int c) {
        if (i == len) return 0;
        if (c == -1) return min(1+dp(i+1, c), dp(i+1, i));

        if (cache[i][c] == -1) {

            if (s[i] < s[c]) {
                cache[i][c] = 1+dp(i+1, c);
            }
            else {
                cache[i][c] = min(1+dp(i+1, c), dp(i+1, i));
            }
        }
        
        return cache[i][c];
    }
};