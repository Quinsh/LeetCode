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
 * INTUITION:
 * 
 * TC: O(n) - number of nodes
 * SC: O(H) - height of the tree
 * 
 * TOIMPROVE: 
 */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return path(root, targetSum, 0);
    }
    bool path(TreeNode *root, int target, int sum) {
        if (!root->left && !root->right)
            if (sum+root->val == target) return true;
        
        return path(root->left, target, sum+root->val) || path(root->right, target, sum+root->val);
    }
};

// or we can do top down: 
class Solution {
private:
    bool ans = false;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        path(root, targetSum, 0);
        return ans;
    }
    void path(TreeNode *root, int &target, int sum) {
        if (!root) return;

        sum += root->val;
        if (!root->left && !root->right){
            if (sum == target)
                ans = true;
            return;
        }

        path(root->left, target, sum);
        path(root->right, target, sum);
    }
};