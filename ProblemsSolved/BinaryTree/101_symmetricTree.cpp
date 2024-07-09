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
 * INTUITION: do the inorder(left->right) traversal in root->left, and inorder(right->left) traversal in root->right and compare if the array built is same
 * 
 * TC: O(N) for iterating thorugh the tree.
 * SC: O(N) for making the comparison array
 * 
 * TOIMPROVE: Ok, but come up with a cleaner way.
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<int> leftsubtree, rightsubtree;
        inOrderLeft(root->left, leftsubtree);
        inOrderRight(root->right, rightsubtree);

        // compare if the array built is the same.
        if (leftsubtree.size() != rightsubtree.size()) return false;
        for (int i = 0; i < leftsubtree.size(); i++) {
            if (leftsubtree[i] != rightsubtree[i]) return false;
        }
        return true;
    }
    void inOrderLeft(TreeNode *root, vector<int>& ans) {
        if (!root) {
            ans.push_back(INF);
            return;
        }
        if (isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }
        inOrderLeft(root->left, ans);
        ans.push_back(root->val);
        inOrderRight(root->right, ans);
    }
    void inOrderRight(TreeNode *root, vector<int>& ans) {
        if (!root) {
            ans.push_back(INF);
            return;
        }
        if (isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }
        inOrderRight(root->right, ans);
        ans.push_back(root->val);
        inOrderLeft(root->left, ans);
    }
    bool isLeaf(TreeNode *root) {
        return !(root->left || root->right);
    }
};

// The editorial solution (OMG how I couldn't think of this?)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        
        return left->val == right->val
            && isMirror(left->left, right->right)
            && isMirror(left->right, right->left);
    }
};
