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
 * INTUITION: if root->val is val, return that, else search recursively. 
 * 
 * TC: O(D) - depth of the tree (since the tree can be unbalanced)
 * SC: O(D) - recursed up to the depth of the tree.
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return root;
        if (root->val == val) return root;

        if (root->val < val) return searchBST(root->right, val);
        else return searchBST(root->left, val);
    }
};