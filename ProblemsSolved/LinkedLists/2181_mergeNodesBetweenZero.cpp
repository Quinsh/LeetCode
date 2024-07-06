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
 * DATE: 2024.07.04
 * INTUITION:
 * 
 * TC: O(1)
 * SC: 
 * 
 * TOIMPROVE: 
 */

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        
        ListNode *newhead = new ListNode(-1);
        ListNode *cur = newhead;
        int sum = 0;
        while (head != nullptr) {
            if (head->val == 0) {
                ListNode *newnode = new ListNode(sum);
                cur->next = newnode;
                cur = cur->next;
                sum = 0;
            }
            else {
                sum += head->val;
            }
            
            head = head->next;
        }
        
        ListNode *headToReturn = newhead->next->next;
        delete newhead->next;
        delete newhead;
        return headToReturn;
    }
};