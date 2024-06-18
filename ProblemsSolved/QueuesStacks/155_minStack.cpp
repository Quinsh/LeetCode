#include <utility>
#include <stack>

using namespace std;
/**
 * INTUITION: 
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: it was hard to think of this data structure. I was thinking of way to track min val separately in O(n) time, but didn't think of this nested structure.
 * I should keep nested structures in mind. 
*/
class MinStack {
private:
    stack<pair<int, int>> pairstack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (pairstack.empty()) {
            pairstack.emplace(val, val);
        }
        else {
            int lastMin = getMin();
            int curMin = lastMin < val ? lastMin : val;
            pairstack.emplace(val, curMin);
        }
    }
    
    void pop() {
        pairstack.pop();
    }
    
    int top() {
        return pairstack.top().first;
    }
    
    int getMin() {
        return pairstack.top().second;
    }
};