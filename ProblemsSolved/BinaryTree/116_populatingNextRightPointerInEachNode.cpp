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
 * DATE: 2024.07.11
 * INTUITION: do a BFS.
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    Node* connect(Node* root) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            if (!q.front()) break; // this line is when we iterate the last depth, and it starts adding Nullptr in the q
            int s = q.size();
            for (int i = 0; i < s-1; i++) {
                Node *cur = q.front(); q.pop();
                cur->next = q.front();
                q.push(cur->left); q.push(cur->right);
            }
            Node *last = q.front(); q.pop();
            last->next = nullptr;
            q.push(last->left); q.push(last->right);
        }
        return root;
    }
};