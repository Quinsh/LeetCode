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
 * INTUITION: swap the nodes recursively (swap the first 2, and merge with the recursive result)
 * 
 * TC: O(N) - linear processing
 * SC: O(N) - recursion stack space
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;

        // swap the first two
        ListNode *nextRec = head->next->next;
        ListNode *second = head->next;
        second->next = head;
        head = second;
        head->next->next = swapPairs(nextRec);
        return head;
    }
};
