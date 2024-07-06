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
 * DATE: 2024.07.05
 * INTUITION: traverse the array and update the min everytime, while save the first and last critical point to get the max at the end.
 * 
 * TC: O(N)
 * SC: O(1)
 * 
 * TOIMPROVE: OMG Need to improve this. this is so bad code XD haha
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        
        ListNode *cur = head;
        bool lastValLessThanLast = false;
        bool lastValBiggThanLast = false;
        int lastVal = 0;
        int pos = 1;
        int firstCritPoint = 0;
        int lastCritPoint = 0;
        int smallestDiff = INT_MAX;

        while (cur != nullptr) { // traverse the list
            if (!lastVal) goto end;
            if (lastVal > cur->val) {
                if (lastValLessThanLast) {
                    if (!firstCritPoint) firstCritPoint = pos-1;
                    int temp = lastCritPoint;
                    lastCritPoint = pos-1;
                    if (temp) {
                        int diff = lastCritPoint - temp;
                        smallestDiff = smallestDiff < diff ? smallestDiff : diff;
                    }
                }
                lastValBiggThanLast = true;
                lastValLessThanLast = false;
            }
            else if (lastVal < cur->val) {
                if (lastValBiggThanLast) {
                    if (!firstCritPoint) firstCritPoint = pos-1;
                    int temp = lastCritPoint;
                    lastCritPoint = pos-1;
                    if (temp) {
                        int diff = lastCritPoint - temp;
                        smallestDiff = smallestDiff < diff ? smallestDiff : diff;
                    }
                }
                lastValLessThanLast = true;
                lastValBiggThanLast = false;
            }
            else {
                lastValBiggThanLast = false;
                lastValLessThanLast = false;
            }
            end: lastVal = cur->val;
            pos++;
            cur = cur->next;
        }

        if (!lastCritPoint || firstCritPoint == lastCritPoint) return {-1, -1};
        else {
            return {smallestDiff, (lastCritPoint-firstCritPoint)};
        }
    }
};