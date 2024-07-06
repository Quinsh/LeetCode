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
 * INTUITION: we need to do O(1) processing each iteration of search. What can we know in O(1) that would determine if we should iterate on left half or right half?
 * [3 3 3 1 3] if we have this, what tells that this is an array of 1 3 3 3 3 rotated 3 times, or that we should iterate on the right half? It's not something about mid element and rightmost/leftmost element.
 * because if we had [3 1 3 3 3], the same logic would not apply. all mid/rightmost/leftmost == 3, but we search left this time.
 * I can't figure out. From what point of my thought flow was I wrong? What should I have thought? Let's check the answer.
 * 
 * OK. I wasn't wrong. They just do r-- when nums[mid] == nums[r], which would cause O(n) in worst situations like [3 1 3 3 3 3 3 3 3 3].
 * There just isn't O(logN) approach. 
 * 
 * TC: O(logn)
 * SC: O(1)
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid;
        
        while (l < r) {
            mid = l + (r-l)/2;
            if (nums[mid] == nums[r])       r--;
            else if (nums[mid] < nums[r])   r = mid;
            else if (nums[mid] > nums[r])   l = mid+1;
        }
        
        return nums[r];
    }
};