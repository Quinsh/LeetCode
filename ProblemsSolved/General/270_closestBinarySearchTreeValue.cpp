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
 * DATE: 2024.06.29
 * INTUITION: given a root, if target is equal to the root value, return it.
 * if target is less than root, we need to explore the left part as well as the answer can lie between the range of the left child and the root.
 * if target is bigger than root, we explore the range btw root and right node.
 * 
 * when we say `explore`, we basically compare which one is closest to target - the root node or the return value of recursing on the child node.
 * 
 * TC: O(height) - it's not O(logn) cuz the tree might not be balanced
 * SC: O(1)
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (root->left && target < root->val) {
            return lowest_abs(root->val, closestValue(root->left, target), target);
        }
        else if (root->right && target > root->val) {
            return lowest_abs(root->val, closestValue(root->right, target), target);
        }
        return root->val;
    }

    double lowest_abs(double val1,double val2, double target) {
        if (abs(val1 - target) < abs(val2 - target)) {
            return val1;
        }
        else if (abs(val1 - target) > abs(val2 - target)) {
            return val2;
        }
        else {
            if (val1 < val2) return val1;
            else return val2;
        }
    }
};