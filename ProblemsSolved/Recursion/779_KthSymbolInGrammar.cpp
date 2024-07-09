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
 * DATE: 2024.07.06
 * INTUITION: we can recurse like pascal triangle recursion. easy.
 * 
 * TC: O(n) - we recurse n times
 * SC: O(n) - O(1) for each recursion * n, the maximum recursion depth
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;

        int prev = kthGrammar(n-1, (k+1)/2);
        if (prev == 0) {
            if (k & 1) return 0;
            else return 1;
        }
        else {
            if (k & 1) return 1;
            else return 0;
        }
    }
};