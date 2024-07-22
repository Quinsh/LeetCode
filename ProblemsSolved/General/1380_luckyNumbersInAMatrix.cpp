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
 * DATE: 2024.07.19
 * INTUITION: row traversal to find the smallest, then column traversal
 * 
 * TC: O(N) - N being number of cells
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        unordered_map<int, vector<int>> map; // maps column number of the minimum element in the row --> minimum element in the row.
        vector<int> ans;
        for(const auto &row : matrix) {
            auto it = min_element(btoe(row));
            map[it-row.begin()].push_back(*it);
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            int ind = -1, max = -99999999;
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[j][i] >= max) {
                    ind = j;
                }
            }
            if (map.count(i)) {
                for (const auto &x : map[i]) {
                    if (x == matrix[ind][i]) ans.push_back(x);
                }
            }
        }
        return ans;
    }
};