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
 * INTUITION: the very intuitive solution would be the brute force.. like returning 2 + deleteAndEarn[2, 4] if the array is like [2,2,3,3,3,4]
 * Ok. We can make a frequency array from 0 to maximum element in the array. and then do DP from there. 
 * 
 * TC: O(N)
 * SC: 
 * 
 * TOIMPROVE: do the iterative apprach as well.
 */
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        map<int, int> freq;
        for (const auto &n : nums) {
            freq[n]++;
        }

        vector<int> dp; dp.resize(*max_element(nums.begin(), nums.end()) + 1);
        dp[0] = 0;
        dp[1] = 1 * freq[1];
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + i*freq[i]);
        }
        return dp[dp.size()-1];
    }
};