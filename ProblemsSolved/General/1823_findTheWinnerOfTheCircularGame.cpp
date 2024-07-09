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
 * DATE: 2024.07.08
 * INTUITION: enqueue everything, then while there are >= 1 in the queue, pop for k-1 times and put it back to the queue. pop the kth one. continue.
 * 
 * TC: O(N*K)
 * SC: O(N)
 * 
 * TOIMPROVE: reduce time complexity to O(N) or O(1).
 */
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < k-1; j++) {
                q.push(q.front()); q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};