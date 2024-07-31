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
 * DATE: 2024.07.31
 * INTUITION: use a map to represent the description and build tree recursively.
 * 
 * TC: 
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    unordered_map<int, unordered_map<int, int>> desc; // rootval-left/right-childval
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> set;
        for (const auto &d : descriptions) {
            desc[d[0]][d[2]] = d[1];
            set.insert(d[1]);
        }
        // find the root
        int rootval = 0;
        for (const auto &d : descriptions) {
            if (set.find(d[0]) == set.end()) {
                rootval = d[0];
                goto found;
            }
        } found:
        TreeNode *root= new TreeNode(rootval);
        build(root);
        return root;
    }

    void build(TreeNode* root) {
        if (desc[root->val][0]) {
            root->right = new TreeNode(desc[root->val][0]);
            build(root->right);
        }
        if (desc[root->val][1]) {
            root->left = new TreeNode(desc[root->val][1]);
            build(root->left);
        }
    }
};