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
 * DATE: 2024.07.10
 * INTUITION: solve recursively
 * 
 * TC: O(N^2) - it does a O(N) search each recursion, and there are O(N) recursions
 * SC: O(1)
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *ans = tree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        return ans;
    }
    TreeNode* tree(vi &inorder, int l1, int r1, vi &postorder, int l2, int r2) {
        // BASE CASE
        if (l1 > r1 || l2 > r2) return nullptr;

        // RECURSIVE CASE
        TreeNode *root = new TreeNode(postorder[r2]);
        int pivot = find(inorder.begin()+l1, inorder.begin()+l2, postorder[r2]) - inorder.begin();
        root->left = tree(inorder, l1, pivot-1, postorder, l2, l2+(pivot-l1-1));
        root->right = tree(inorder, pivot+1, r1, postorder, l2+(pivot-l1), r2-1);
        return root;
    }
};

