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
 * DATE: 2024.07.22
 * INTUITION:
 * 
 * TC: O(min(p, q))
 * SC: O(H) - height of the minimum tree btw p and q
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!(p||q)) return true; // if they are both null. 
        return (p->val == q->val) &&
                isSameTree(p->left, p->left) && isSameTree(p->right, q->right);
    }
};