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
 * INTUITION: the first intuition I had was to use (i, witdhSum) as the states for DP. But ChatGPT is telling this is 1d DP problem and I'h shocked.
 * Actually, I might have to use 3 states, cuz I don't know how to get the maximum height of current shelf.
 * Let's just use 3 states.
 * 
 * TC: O(N^2*H)
 * SC: O(N^2*1000)
 * 
 * TOIMPROVE: this was hard.. let's practice more with this question. Try to decrease dimension.
 */
class Solution {
private:
    // this is a tip. lol. if we don't need to use all the space in the dimension, just use a nested map.
    // if we use a 3d vector, it gives Memory Limit Exceeded.
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> cache;
    vector<vector<int>> books;
    int shelfWidth;
public:
    int minHeightShelves(vector<vector<int>>& _books, int _shelfWidth) {
        books=_books; shelfWidth=_shelfWidth;
        return dp(0, 0, 0);
    }
    
    int dp(int i, int w, int h) {
        // no more books to put
        if (i == books.size()) return h;

        if (!cache[i][w][h]) {
            if (w + books[i][0] <= shelfWidth) { // book can be put in the current level of Shelf.
                // choose btw putting the book in the current shelf or in the next shelf.
                cache[i][w][h] = min(dp(i+1, w+books[i][0], max(h, books[i][1])), h + dp(i+1, books[i][0], books[i][1]));
            }
            else {
                cache[i][w][h] = h + dp(i+1, books[i][0], books[i][1]);
            }
        }
        
        return cache[i][w][h];
    }
};


// vv 1D DP SOLUTION WTF....??? vv
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int width = 0, height = 0;
            // Try to place books[i-1] to books[j-1] on the current shelf
            for (int j = i; j > 0; --j) {
                width += books[j-1][0];
                if (width > shelfWidth) break;
                height = max(height, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + height);
            }
        }
        
        return dp[n];
    }
};