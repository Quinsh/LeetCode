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
 * DATE: 2024.06.20
 * INTUITION:
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: actually, we need to invert only once; after pushing. 
*/
class Solution225 {
private:
    queue<int> q;
    int size;
public:
    Solution225() {
        size = 0;
    }
    
    void push(int x) {
        invertQueue();
        q.push(x);
        invertQueue();
        size++;
    }
    
    int pop() {
        int ret = q.front();
        q.pop();
        size--;
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

    void invertQueue() {
        for (int i = 0; i < size; i++) {
            int x = q.front();
            q.pop();
            q.push(x);            
        }
    }
};