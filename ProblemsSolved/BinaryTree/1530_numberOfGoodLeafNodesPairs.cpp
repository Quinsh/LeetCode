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
 * DATE: 2024.07.18
 * INTUITION: Use hashmap to store the leaf nodes and their distances (from bottom to up). each recursion, calculate
 * if there are pairs for leafnodes in left & right children. Ok this explanation is a bit weird.
 * 
 * TC: O(N * D^2) - O(N) traversal, and we calculate cnt in a double loop that goes up to D (for distance), so D^2 checking for each node.
 * SC: O(N*D) 
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    unordered_map<TreeNode*, map<int, int>> map; // TreeNode -mapsto-> map<distance, leafnodes>
    int ans = 0;
public:
    int countPairs(TreeNode* root, int distance) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        count(root, distance);
        return ans;
    }
    void count(TreeNode* root, int distance) {
        if (!root) return;
        if (!root->left && !root->right) {
            std::map<int, int> temp;
            temp[1] = 1;
            map[root] = temp;
            return;
        }

        count(root->left, distance);
        count(root->right, distance);

        if (root->left && root->right) {
            for (const auto &pair : map[root->left]) {
                for (const auto &pair2 : map[root->right]) {
                    if (pair.first + pair2.first <= distance) {
                        int cnt = pair.second * pair2.second;
                        ans += cnt;
                    }
                    else break; // I can break out here because map is sorted (in increasing distane)
                }
            }
        }

        std::map<int, int> temp;
        if (root->left) {
            for (const auto &pair : map[root->left])
                temp[pair.first+1] += pair.second;
        }
        if (root->right) {
            for (const auto &pair : map[root->right])
                temp[pair.first+1] += pair.second;
        }
        map[root] = temp;
    }
};