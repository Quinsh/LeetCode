#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

/**
 * DATE: 2024.06.21
 * INTUITION: Basically, invert the positions in stack by popping and pushing to another stack everytime we do push()
 * 
 * TC: push() -> O(n), Others: O(1)
 * SC: O(n) cuz we use one stack the same size as queue.
 * 
 * TOIMPROVE: how can we amortize every operations into O(1)?
*/
class Solution232 {
private:
    stack<int> s;
public:
    Solution232() {
        
    }
    
    void push(int x) {
        stackInvert();
        s.push(x);
        stackInvert();
    }
    
    int pop() {
        if (empty()) {
            return -1;
        }
        int ans = s.top();
        s.pop();
        return ans;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }

    void stackInvert() {
        stack<int> new_stack;
        while (!s.empty()) {
            new_stack.push(s.top());
            s.pop();
        }
        s = new_stack;
    }
};