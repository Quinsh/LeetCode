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
 * INTUITION: first, make a max heap, and then pop k times. 
 * 
 * TC: O(n + klogn) - Because it's O(n) for building the max heap, then, O(logn) for popping each k times. 
 * SC: O(n) - uses one vector.
 * 
 * TOIMPROVE: 
*/
class Solution215 {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // make nums itself into heap
        make_heap(nums.begin(), nums.end());

        for (int i = 0; i < k-1; i++) {
            pop_heap(nums.begin(), nums.end());
        }

        return nums[0];
    }
};

/**
 * DATE: 2024.06.23
 * INTUITION: make a min heap with size K, then, iterate through N-K elements adding it to the minHeap if the number is greater than the minimum.
 * 
 * TC: O(K + (N-K)(logK)) which simplifies into O(K) to make the heap, then for N-K, we do O(logK)
 * SC: O(K)
 * 
 * TOIMPROVE: 
*/
class Solution215_2 {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // make a min heap with size K
        priority_queue<int, vector<int>, greater<int>> minheap{nums.begin(), nums.begin() + k};

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > minheap.top()) {
                minheap.pop();
                minheap.push(nums[i]);
            }
        }

        return minheap.top();
    }
};