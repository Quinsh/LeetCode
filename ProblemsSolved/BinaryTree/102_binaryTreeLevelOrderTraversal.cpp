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
 * INTUITION: just BFS
 * 
 * TC: O(N)
 * SC: O(N)
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            vector<int> level = {};
            for (int i = 0; i < s; i++) {
                TreeNode *cur = q.front(); q.pop();
                level.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

// now the recursive solution
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(ans, root, 0);
        return ans;
    }

    void helper(vector<vector<int>> &ans, TreeNode *root, int level) {
        if (!root) return;
        if (ans.size() > level) ans[level].push_back(root->val);
        else ans.push_back({root->val});
        helper(ans, root->left, level+1);
        helper(ans, root->right, level+1);
    }
};