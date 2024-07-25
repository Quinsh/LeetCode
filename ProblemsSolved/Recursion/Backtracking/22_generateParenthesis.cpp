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
 * DATE: 2024.07.22
 * INTUITION: pretty easy to figure out the rules for pruning the tree for backtracking. Just see the comment.
 * 
 * TC: ah this is hard to figure out...
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        build(ans, s, 0, 0, 0, n*2);
        return ans;
    }

    void build(vector<string> &ans, string &s, int leftP, int stack, int k, int n) { // leftP is `(` count, stack is to keep track of matching parenthesis
        if (k == n) {
            ans.push_back(s);
            return;
        }

        if (leftP < n/2) { // when proceeding to add `(` we just need to care if there is already more than enough `(`
            s += "(";
            build(ans, s, leftP+1, stack+1, k+1, n);
            s.pop_back();
        }
        if (stack > 0) { // when proceeding to add `)` we need to care if there is a matching `(` in `s` so far.
            s += ")";
            build(ans, s, leftP, stack-1, k+1, n);
            s.pop_back();
        }
    }
};