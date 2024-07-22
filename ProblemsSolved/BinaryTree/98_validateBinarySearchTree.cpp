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
 * DATE: 2024.07.14
 * INTUITION: ooohhhhhh wait we can use a hashmap to store lowest val, highest val for each Node. This makes things so much easier.
 * 
 * TC: O(N) - N for Nodes
 * SC: O(N) 
 * 
 * TOIMPROVE: haha using hashmap wasn't the `right` way. My solution is at 90% percentile TC lol. At least it was creative. 
 */
class Solution {
private:
    unordered_map<TreeNode*, pair<int, int>> map;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) {
            map[root] = {root->val, root->val};
            return true;
        }

        if (!isValidBST(root->left) || !isValidBST(root->right))
            return false;
        
        if (map.find(root->left) != map.end() && map[root->left].second >= root->val || 
            map.find(root->right) != map.end() && map[root->right].first <= root->val)
            return false;

        int min = 0, max = 0;
        if (!root->left) min = root->val;  else min = map[root->left].first;
        if (!root->right) max = root->val; else max = map[root->right].second;
        map[root] = {min, max};

        return true;
    }
};

// now let's solve in the editorial way:
// OMG I could have just used inorder traversal. I'm so dumb.
class Solution {
private:
    TreeNode *prev = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        if (!isValidBST(root->left) || prev->val >= root->right->val) return false;
        prev = root;
        
        if (root->right && prev->val >= root->right->val || !isValidBST(root->right)) return false;
        return true;
    }
};