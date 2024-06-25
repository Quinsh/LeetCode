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
 * DATE: 2024.06.25
 * INTUITION: [1 3 8 5] 1+3 = 4, 4+8 = 12, 12+5 = 17 -> 33 this is higher than
 *            [1 3 8 5] 1+3 = 4, 4+5 = 9, 9+8 = 17 -> 30 because the things we added first became big and we re-added that big number.
 * So, we wanna minimaze making big numbers in the beginning.
 * maybe just add things in the minheap and then push the added things again?
 * 
 * TC: O(NlogN) - O(N) for making the heap and O(NlogN) for pushing and popping N times.
 * SC: O(N) - for making the heap of size N.
 * 
 * TOIMPROVE: none
*/
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        // O(N) for making heap
        priority_queue<int, vector<int>, greater<>> minheap(sticks.begin(), sticks.end());
        
        int ans = 0;
        // O(NlogN) for popping and pushing
        int size = sticks.size();
        for (int i = 0; i < size-1; i++) {
            int first = minheap.top(); minheap.pop();
            int second = minheap.top(); minheap.pop();
            int sum = first + second;
            ans += sum;
            minheap.push(sum);
        }
        return ans;
    }
};