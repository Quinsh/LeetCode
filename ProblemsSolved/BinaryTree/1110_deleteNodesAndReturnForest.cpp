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
 * DATE: 2024.07.17
 * INTUITION: store the root in the ans or not (depending on if it should be deleted or not), 
 * and then disconnect the childs as we go (if those should be deleted).
 * 
 * TC: O(N) - need to visit all nodes
 * SC: O(N) - hashmap, recursion stack for unbalanced tree
 * 
 * TOIMPROVE: notin
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> deleteset;
        for (const auto &x : to_delete) deleteset.insert(x);

        helper(root, deleteset, ans, true);
        return ans;
    }
    void helper(TreeNode *root, unordered_set<int> &deleteset, vector<TreeNode*> &ans, bool startnew) {
        if (!root) return;

        if (deleteset.find(root->val) != deleteset.end()) {
            helper(root->left, deleteset, ans, true);
            helper(root->right, deleteset, ans, true);
        }
        else { // if the root is not in the set
            if (startnew) ans.push_back(root);
            helper(root->left, deleteset, ans, false);
            helper(root->right, deleteset, ans, false);
            if (root->left && deleteset.find(root->left->val) != deleteset.end()) root->left = nullptr;
            if (root->right && deleteset.find(root->right->val) != deleteset.end()) root->right = nullptr;
        }
    }
};