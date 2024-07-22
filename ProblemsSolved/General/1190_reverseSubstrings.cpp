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
 * DATE: 2024.07.11
 * INTUITION: we can iterate and use a stack, but I wanna solve with recursion. 
 * actually, using recursion kinda requires iteration as well. I'll just use iteration.
 * 
 * TC: O(n^2) in worst case of something like (s(s(s(s(s)s)s)s)s)
 * SC: O(n) in worst case
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> open;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == '(') open.push(i);
            else if (s[i] == ')') {
                int start = open.top() + 1; open.pop();
                reverseContent(s, start, i-1); // reverse operation is O(r-l)
            }
        }
        string ans = "";
        for (const auto &c : s) {
            if (c != '(' && c != ')') ans += c;
        }
        return ans;
    }

    void reverseContent(string &s, int l, int r) {
        while (l < r)
            swap(s[l], s[r]);
            l++; r--;
    }
};