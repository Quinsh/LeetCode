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
 * DATE: 2024.07.16
 * INTUITION: record the path from root to the values. Then, find the path from one value to another.
 * 
 * TC: O(N) - nodes
 * SC: O(H) - height of the tree
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<int> pathStart, pathDest;
        recordPath(root, pathStart, startValue); recordPath(root, pathDest, destValue);
        int lca = 0; // lca for lowest common ancestor
        int min = pathStart.size() < pathDest.size() ? pathStart.size() : pathDest.size();
        while (lca < min && pathStart[lca] == pathDest[lca]) lca++; lca--;
        
        string ans = "";
        for (int i = 0; i < pathStart.size()-lca-1; i++) ans += "U";
        TreeNode *cur = root;
        for (int i = 0; i < pathDest.size()-1; i++) {
            if (cur->left && pathDest[i+1] == cur->left->val) {
                cur = cur->left;
                if (i >= lca) ans += "L";
            }
            else if (cur->right && pathDest[i+1] == cur->right->val) {
                cur = cur->right;
                if (i >= lca) ans += "R";
            }
        }
        return ans;
    }
    bool recordPath(TreeNode *root, vector<int> &path, int target) {
        if (!root) return false;
        
        path.push_back(root->val);
        if (root->val == target)
            return true;
        
        if (recordPath(root->left, path, target) || recordPath(root->right, path, target)) {
            return true;
        }
        path.pop_back();
        return false;
    }
};