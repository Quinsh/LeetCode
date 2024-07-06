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
 * DATE: 2024.07.02
 * INTUITION: use array (instead of set)
 * 
 * TC: O(n) - linear search
 * SC: O(m) - array of nums.maxelement used.
 * 
 * TOIMPROVE: 
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        int max = *max_element(btoe(nums));
        vi counts; counts.resize(max+1);
        
        for (const auto &n : nums) {
            if (!counts[n]) counts[n]++;
            else return n;
        }

        return -1;
    }
};