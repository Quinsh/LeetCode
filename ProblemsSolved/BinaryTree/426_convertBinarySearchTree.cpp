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
 * DATE: 2024.07.22
 * INTUITION: just do inorder.
 * 
 * TC: O(N)
 * SC: O(H)
 * 
 * TOIMPROVE: nothign. easy
 */
class Solution {
private:
    Node *prev = nullptr;
    Node *first = nullptr, *last = nullptr;
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        inorder(root);
        first->left = last;
        last->right = first;
        return first;
    }
    void inorder(Node *root) {
        if (!root) return;
        
        inorder(root->left);

        if (prev) { // if there is prev (which will always be the case except the very first left node.)
            prev->right = root;
            root->left = prev;
        }
        else { // if there is no prev this is bcz previous recursions did not modify prev, i.e., this is the first node.
            first = root;
        }
        prev = root;

        // if there is no root->right, this will be the last node in some subtree (it might not be the last last, but as this is executed, at the end, it updates to the very last node).
        if (!root->right) last = root;

        inorder(root->right);
    }
};