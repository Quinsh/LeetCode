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
 * INTUITION: just mathematical solution
 * 
 * TC: O(1)
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    int passThePillow(int n, int time) {
        int div = time / (n-1);
        int rem = time % (n-1);
        if (div & 1) {
            return n - rem;
        }
        else {
            return rem + 1;
        }
    }
};