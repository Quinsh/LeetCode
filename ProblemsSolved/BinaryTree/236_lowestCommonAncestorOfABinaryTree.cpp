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
#include "TreeNode.h"

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
 * DATE: 2024.07.13
 * INTUITION: let's record the path from the root to p and to q, and see the node that is same for both paths.
 * 
 * TC: O(N) - 
 * SC: O(H) - height of the node
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        stack<TreeNode*> p_trace, q_trace;
        recordPath(p_trace, root, p);
        recordPath(q_trace, root, q);
        while (q_trace.size() != p_trace.size()) {
            if (q_trace.size() > p_trace.size())
                q_trace.pop();
            else
                p_trace.pop();
        }
        while (p_trace.size()) {
            if (p_trace.top()->val == q_trace.top()->val) {
                return p_trace.top();
            }
            else {
                p_trace.pop(); q_trace.pop();
            }
        }
        return nullptr;
    }
    bool recordPath(stack<TreeNode*> &stack, TreeNode *root, TreeNode *t) {
        if (!root) return false;

        stack.push(root);
        if (root->val == t->val) return true;

        // if found in subtrees
        if (recordPath(stack, root->left, t) || recordPath(stack, root->right, t))
            return true;
        
        // if not found in subtrees
        stack.pop();
        return false;
    }
};