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
 * DATE: 2024.07.11
 * INTUITION: 
 * 
 * TC: O(NlogN) - T(n) = 2T(n/2) + O(n). just use master theorem. But visualizing this, we can also know this is similar to merge sort TC.
 * but, worst case O(n^2)
 * SC: O(H) - for the height of the tree.
 * 
 * TOIMPROVE: reduce TC of this algorithm. We can optimize this by making a hashmap indicating the position of each element in inorder array
 * to avoid searching everytime with O(n) TC.
 * 
 * TCAFTER: O(N) for N nodes. 
 */
class Solution {
private:
    unordered_map<int, int> inorder_map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        for (int i = 0; i < inorder.size(); i++) inorder_map[inorder[i]] = i;
        TreeNode *ans = helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return ans;
    }

    TreeNode *helper(vector<int> &pre, int p1, int p2, vector<int> &in, int i1, int i2) {
        if (p1 == p2) return new TreeNode(pre[p1]); // is leaf (no need to add this, but adding this would stop from recursing one more when it's leaf)
        if (p1 > p2) return nullptr; // is none

        TreeNode *root = new TreeNode(pre[p1]); // construct the root node. pre[p1] is the root val
        int pivot = inorder_map[pre[p1]]; // find pivot in inorder array - O(1) using map
        
        root->left = helper(pre, p1+1, p1+pivot-i1, in, i1, i1+pivot-1);
        root->right = helper(pre, p1+pivot-i1+1, p2, in, pivot+1, i2);
        
        return root;
    }
};