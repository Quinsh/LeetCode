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
 * DATE: 2024.07.09
 * INTUITION: just simulate the restaurant
 * 
 * TC: O(N)
 * SC: O(1)
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int lastWaitTime = customers[0][0];
        double sum = 0;

        for (const auto &customer : customers) {
            int timeTillServed = lastWaitTime > customer[0] ? lastWaitTime - customer[0] : 0;
            int totalWaitTime = timeTillServed + customer[1];
            sum += totalWaitTime;
            lastWaitTime = lastWaitTime > customer[0] ? lastWaitTime + totalWaitTime - timeTillServed : customer[0] + totalWaitTime - timeTillServed;
        }

        return sum / customers.size();
    }
};