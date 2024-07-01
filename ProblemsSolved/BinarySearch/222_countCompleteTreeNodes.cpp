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

using namespace std;

/**
 * DATE: 2024.06.28
 * INTUITION: solved with solution. a nested binary search.
 * 
 * TC: O(logn * logn) = O(log^2 n) we do binary search for each binary search
 * SC: O(1) - no big structures are used.
 * 
 * TOIMPROVE: 
*/
struct TreeNode {
    int val;
    TreeNode *left;  
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        // count the depth first
        int d = 1;
        for (TreeNode* cur = root; cur->left != nullptr; d++, cur = cur->left);
        if (d==1) return 1;
        d--; // d should exclude the last depth

        int ans = pow(2, d) - 1;
        // binary search the rightmost existing node in the last row
        int l = 1, r = pow(2,d), mid = 0;
        while (l < r) { // at the end, l == r
            mid = l + (r-l+1)/2;
            if (exists(root, mid, d)) l = mid;
            else {
                r = mid-1;
            }
        }
        if (r == 0) return ans;
        else return ans+mid;
    }

    bool exists(TreeNode* root, int target, int d) {
        int l = 1, r = pow(2,d);
        while (l<r) {
            int mid = l + (r-l)/2;
            if (target <= mid) {
                if (root->left) root = root->left;
                else return false;
                r = mid;
            }
            else {
                if (root->right) root = root->right;
                else return false;
                l = mid + 1;
            }
        }
        return true;
    }
};