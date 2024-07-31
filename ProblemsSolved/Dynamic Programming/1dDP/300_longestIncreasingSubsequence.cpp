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
 * DATE: 2024.07.26
 * INTUITION: classic 1d dp problme
 * 
 * TC: O(n^2)
 * SC: O(n)
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    vector<int> nums;
    vector<int> cache;
public:
    int lengthOfLIS(vector<int>& _nums) {
        cache.resize(nums.size(), -1);
        cache[0] = 1;
        nums=_nums;
        dp(nums.size()-1);
        return *max_element(cache.begin(), cache.end());
    }

    int dp(int r) {
        if (cache[r] == -1) {
            int maxseq = 1;
            for (int i = 0; i < r; i++) {
                int DP = dp(i);
                if (DP >= maxseq && nums[i] < nums[r]) {
                    maxseq = DP+1;
                }
            }
            cache[r] = maxseq;
        }
        return cache[r];
    }
};