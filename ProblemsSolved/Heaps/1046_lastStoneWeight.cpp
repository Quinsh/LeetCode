#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * DATE: 2024.06.23
 * INTUITION: use maxheap. Pop two thigs, calculate and then 
 * 
 * TC: O(NlogN)
 * SC: O(N) - stores the stones in the heap of same size
 * 
 * TOIMPROVE: 
*/
class Solution1046 {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap(stones.begin(), stones.end());
        
        while (maxheap.size() != 1) {
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();
            
            int diff = abs(x - y);
            if (diff) {
                maxheap.push(diff);
            }
            if (maxheap.size() == 0) {
            return 0;
            }
        }
        return maxheap.top();
    }
};