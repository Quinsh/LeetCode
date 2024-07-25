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
 * INTUITION: very classic 2d dp problem.
 * 
 * TC: O(MN)
 * SC: O(MN)
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    vector<vector<int>> cache;
    int e1, e2;
    string text1, text2;
public:
    int longestCommonSubsequence(string _text1, string _text2) {
        e1 = _text1.size(); e2 = _text2.size();
        text1 = _text1; text2 = _text2;
        cache.resize(e1, vector<int>(e2, -1));
        return helper(0, 0);
    }

    int helper(int a, int b) {
        // base case
        if (a==e1 || b==e2) return 0;
        
        if (cache[a][b] == -1) {
            if (text1[a] == text2[b]) 
                cache[a][b] = 1 + helper(a+1, b+1);
            else
                cache[a][b] = max(helper(a+1, b), helper(a, b+1));
        }
        return cache[a][b];
    }
};
