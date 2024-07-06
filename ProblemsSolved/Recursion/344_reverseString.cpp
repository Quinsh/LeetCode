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
 * DATE: 2024.07.05
 * INTUITION: use recursion with helper 
 * 
 * TC: O(N)
 * SC: O(1)
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        helper(0, s.size()-1, s);
    }

    void helper(int l, int r, vector<char>& s) {
        if (l >= r) return;
        swap(s[l++], s[r--]);
        helper(l, r, s);
    }
};