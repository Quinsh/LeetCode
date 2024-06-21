#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

/**
 * DATE: 2024.06.20
 * INTUITION: using recursion is easy. iteratively it's more interesting.
 * 
 * TC: 
 * SC: 
 * 
 * TOIMPROVE: It's better to create one global vector and use it with helper function. Don't recurse on the main function.
*/
class Solution94 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        rec(ans, root);
    }

    void rec(vector<int> &ans, TreeNode *root) {
        if (!root) return;

        rec(ans, root->left);
        ans.push_back(root->val);
        rec(ans, root->right);
    }
};

