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
 * DATE: 2024.07.17
 * INTUITION: Let's find a pivot point and separate the matrix into smaller 4 matrix. Then, we can exclude one submatrix from search each time.
 * 
 * TC: 
 * SC: O(1)
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, target, 0, matrix[0].size()-1, 0, matrix.size()-1);
    }

    bool search(vector<vector<int>> &matrix, int &target, int l, int r, int u, int d) {
        if (l > r || u > d) return false;
        int midx = l + (r-l)/2, midy = 0;
        
        while (midy <= d && matrix[midy][midx] <= target) {
            if (matrix[midy][midx] == target) return true;
            midy++;
        }

        return search(matrix, target, midx+1, r, u, midy-1) || search(matrix, target, l, midx-1, midy, d);
    }
};