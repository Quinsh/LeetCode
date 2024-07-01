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
 * DATE: 2024.06.26
 * INTUITION: keep a vector always sorted by inserting elements into where it should be.
 * 
 * 
 * TC: O(n) - it takes O(n) to insert and O(logn) for binary search
 * SC: O(n) - linear space for data storing.
 * 
 * TOIMPROVE: learn the heap approach
*/
class MedianFinder {
private:
    vector<int> data;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        data.insert(lower_bound(data.begin(), data.end(), num), num);
    }
    
    double findMedian() {
        int s = data.size();
        if (s & 1) {
            return data[int(s/2)];
        }
        else {
            return (data[int(s/2)-1] + data[int(s/2)])/2;
        }
    }
};

/**
 * DATE: 2024.06.26
 * INTUITION: wow this two heap approach is so smart!!
 * 
 * TC: O(logn)
 * SC: O(n)
 * 
 * TOIMPROVE: 
*/
class MedianFinder {
    priority_queue<int> lo;                              // max heap
    priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // Add to max heap

        hi.push(lo.top());                               // balancing step
        lo.pop();

        if (lo.size() < hi.size()) {                     // maintain size property
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? lo.top() : ((double) lo.top() + hi.top()) * 0.5;
    }
};