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
 * INTUITION: store things in a minheap of size k. 
 * Everytime something is pushed, if it is smaller than the top of minheap, it is not added. 
 * If it is bigger than the top, pop the top and push it to the minheap.
 * 
 * TC: O(K + (N-K)logK) --> i.e. O(NlogK)
 * SC: O(K)
 * 
 * TOIMPROVE: 
 * 
 * someone wrote the add function like this and it's so much smarter!!
 * int add(int val) {
        pq.push(val);
        if (pq.size()> k) pq.pop();   
        return pq.top();      
    }
*/
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int k;
public:
    KthLargest(int k, vector<int>& nums)
    {
        k = k;
        int len = nums.size();
        int initPos = min(k, len);
        if (nums.size() == 0) {
            minheap.push(INT_MIN);
        }
        else {
            minheap = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.begin() + initPos);
        }
        for (int i = initPos; i < nums.size(); i++) {
            if (nums[i] > minheap.top()) {
            minheap.pop();
            minheap.push(nums[i]);
            }
            
        }
    }
    
    int add(int val) {
        if (minheap.size() < k) {
            minheap.push(val);
        }
        else {
            if (val > minheap.top()) {
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};