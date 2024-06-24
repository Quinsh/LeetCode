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
 * INTUITION: make a maxHeap of map with custom comparator
 * 
 * TC: O(N + NlogN + KlogN) - O(N) for making the hashmap, NlogN for making the heap, KlogN for popping from the heap.
 * SC: O(N)
 * 
 * TOIMPROVE: 
*/
class Solution347 {

    struct CompareValue {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // count things into a map
        unordered_map<int, int> map;
        for (const auto &n : nums) {
            map[n]++;
        }

        // make a maxHeap of kvpairs comparing based on value (count)
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareValue> maxHeap;
        for(const auto &p : map) {
            maxHeap.push(p);
        }
        
        // pop the k biggests
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return ans;
    }

};
