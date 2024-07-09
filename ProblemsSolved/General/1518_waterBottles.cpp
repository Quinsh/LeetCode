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
 * DATE: 2024.07.07
 * INTUITION: just use loop?
 * 
 * TC: 
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int emptyBottle = 0;
        while (numBottles) {
            ans += numBottles;
            emptyBottle += numBottles;
            numBottles = emptyBottle / numExchange;
            emptyBottle %= numExchange;
        }
        return ans + numBottles;
    }
};