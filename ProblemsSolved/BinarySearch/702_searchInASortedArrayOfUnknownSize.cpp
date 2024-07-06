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

/**
 * DATE: 2024.07.01
 * INTUITION: just do bin search, setting the r to 10^4. We don't even need to care if it is above bound bcz it returns INT_MAX, which is a number, 
 * so we can just use it as part of binary search process.
 * 
 * TC: O(logn)
 * SC: O(1)
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        // but let's not set r to 10^4 because the point of the question is that we DON'T know it's size.
        // we can just double the index until we get INT_MAX, and then we set this as `r`/
        int r = 1;
        while (reader.get(r) != INT_MAX) {
            r *= 2;
        }
        
        // now do binary search
        int l = 0, mid = 0;
        while (l <= r) {
            mid = l + (r-l)/2;
            int got = reader.get(mid);
            if (got == target)
                return mid;
            else if (got < target) 
                l = mid+1;
            else if (got > target)
                r = mid-1;
        }
        return -1;
    }
};

// I saw a very mind-blowing solution:

class Solution {
private:
    int binaryLenSearch(const ArrayReader& reader, int low, int high, int& target) {
        
        if(reader.get(high)==target) {
            return high;             
        }

       if(low<high) {
            if(target>reader.get(high) || reader.get(high)==-1) {
                low=high;
                high=low+high*2;
            }
            else{
                high=low+(high-low)/2;                
            }            
            return(binaryLenSearch(reader, low, high, target));
                   
        }

        return -1;

    }

public:
    int search(const ArrayReader& reader, int target) {
         ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        return(binaryLenSearch(reader,0,2,target));
        
    }
};