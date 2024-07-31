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
 * DATE: 2024.07.24
 * INTUITION:
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    int tribonacci(int n) {
        int first = 0, second = 1, third = 1, last = 0;
        if (n == 0) return first;
        if (n == 1) return second;
        if (n == 2) return third;
        for (int i = 3; i <= n; i++) {
            last = first + second + third;
            first = second;
            second = third;
            third = last;
        }
        return last;
    }
};