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
 * INTUITION:
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return root;
        if (!root->left && !root->right) return {root->val};

        vector<int> ans = {};
        vector<int> left = inorderTraversal(TreeNode *root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        vector<int> right = inorderTraversal(TreeNode *root->right);
        ans.insert(ans.end(), left.begin(), left.end());
    }
};

// iterative approach
class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans = {};
        stack<TreeNode*> stack;
        TreeNode *cur = root;
        
        while (cur != nullptr || !stack.empty()) {
            // put every left branch to stack first
            while (cur != nullptr) {
                stack.push(cur);
                cur = cur->left;
            }
            
            // at this point, cur is NULL
            // take the node stored in stack (the last node in the left branch)
            cur = stack.top(); stack.pop();
            
            ans.push_back(cur->val); // store the value

            // then, go to the right child
            cur = cur->right;

            // in the next iteraion, either cur will be NULL if there is no right child (which means it just pops one more from the stack)
            // or, there is the right child, and we do the same thing we did for the right node (push all the left branch)
        }
        return ans;
    }
};