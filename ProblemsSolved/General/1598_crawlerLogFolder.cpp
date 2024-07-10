#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
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
 * DATE: 2024.07.10
 * INTUITION:
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (const auto &log : logs) {
            if (log == "./") continue;
            if (log == "../") ans--;
            else ans++;
        }
        return ans > 0? ans : 0;
    }
};