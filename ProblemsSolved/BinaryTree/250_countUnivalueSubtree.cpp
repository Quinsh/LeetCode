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
 * DATE: 2024.07.08
 * INTUITION: basically, we recursively check if child nodes are univalue subtrees. 
 * If they are, and their node values are equal to the root->val, the current root is a univalue subtree.
 * In this process, if current root is a univalue subtree increase one to the counter.
 * 
 * TC: O(N)
 * SC: O(H) - height of the tree
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    int ans = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        isUnivalSubtree(root);
        return ans;
    }
    bool isUnivalSubtree(TreeNode *root) {
        if (!root) return true;
        // if it's leaf, it's univalue tree
        if (!root->left && !root->right) {
            ans++;
            return true;
        }
        bool isLeftUnival = isUnivalSubtree(root->left);
        bool isRightUnival = isUnivalSubtree(root->right);

        // if left is not unival tree or it is but the value with cur->val doesn't match, return false
        if (root->left) {
            if (isLeftUnival || root->left->val != root->val)
                return false;
        }
        // if right is not unival tree or it is but the value with cur->val doesn't match, return false
        if (root->right) {
            if (isRightUnival || root->right->val != root->val)
                return false;
        }
        // if both left,right are univalSubtree and the values of their nodes are equal to current, this tree is a univalSubtree.
        ans++;
        return true;
    }
};