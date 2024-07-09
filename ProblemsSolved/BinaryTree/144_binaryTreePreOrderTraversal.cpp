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
 * DATE: 2024.07.06
 * INTUITION: root -> left -> right. Recursively.
 * 
 * TC: O(N) - n being number of nodes
 * SC: O(N) - call stack uses space corresponding to recursion depth O(N) in the worst case of unbalanced tree,
 *            and the total vector<int> used is size of N.
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        if (!root->left && !root->right) return {root->val};
        vector<int> ans = {root->val};
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        ans.insert(ans.end(), btoe(left));
        ans.insert(ans.end(), btoe(right));
        return ans;
    }
};

// Now, iterative solution: O(N), O(N)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> s;
        vector<int> ans;
        s.push(root);
        
        while(!s.empty()) {
            TreeNode *cur = s.top(); s.pop();
            ans.push_back(cur->val);
            
            if (cur->right != nullptr) s.push(cur->right);
            if (cur->left != nullptr) s.push(cur->left);
        }
        return ans;
    }
};