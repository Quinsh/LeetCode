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
 * DATE: 2024.07.23
 * INTUITION: do backtracking.
 * 
 * TC: O(n*n!)
 * SC: O(n^2) since we pass `leftset` by copy (see line 55). 
 * 
 * TOIMPROVE: find a way to reduce SC. 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> leftset(nums.begin(), nums.end());
        vector<int> temp;
        backtrack(ans, temp, leftset);
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &build, unordered_set<int> &leftset) {
        if (leftset.size() == 0) {
            ans.push_back(build);
        }
        
        for (const auto &item : leftset) {
            build.push_back(item);
            unordered_set<int> newset = leftset;
            newset.erase(item);
            backtrack(ans, build, newset);
            build.pop_back();
        }
    }
};
// BETTER APPROACH USING O(N) SC:
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(curr, ans, nums);
        return ans;
    }

    void backtrack(vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (const auto &num : nums) {
            if (find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
                backtrack(curr, ans, nums);
                curr.pop_back();
            }
        }
    }
};