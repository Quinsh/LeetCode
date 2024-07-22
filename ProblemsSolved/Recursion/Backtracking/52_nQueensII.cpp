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
 * DATE: 2024.07.21
 * INTUITION: do backtracking. use the fact that we can place only one queen per row. 
 * So if we can place 1 queen per row for every row, and it reaches the end, it means that it is a correct combination.
 * 
 * TC: O(N!)
 * SC: O(N)
 * 
 * TOIMPROVE: 
 */
class Solution {
private: 
    int ans = 0;
    unordered_set<int> columns, diag, anti_diag;
public:
    int totalNQueens(int n) {
        backtracking(0, n);
        return ans;
    }

    void backtracking(int row, int N) {
        if (row == N) {
            ans++; return;
        }
        
        for (int col = 0; col < N; col++) {
            // Check if placing a queen at (row, col) is safe
            if (!columns.count(col) && !diag.count(row-col) && !anti_diag.count(row+col)) {
                // "place" the queen:
                columns.insert(col); diag.insert(row-col); anti_diag.insert(row+col);
                // continue to build the answer by moving to the next row:
                backtracking(row+1, N);
                // `backtrack` to the current queen placement.
                columns.erase(col); diag.erase(row-col); anti_diag.erase(row+col);
            }
            // else, backtrack (we don't progress to building the answer
            // cuz we know queen shouldn't be placed in this position)
        }
    }
};