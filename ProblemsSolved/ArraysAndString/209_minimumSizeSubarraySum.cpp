//
// Created by Gun woo Kim on 11/20/23.
//
#include <vector>
#include <string>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, r = 0;
    int sum = nums[0];
    int minlen = nums.size();

    while (1){
        // if r reaches the end and sum is less than target, it should stop and return the minlen so far.
        if (r == nums.size()-1 && sum < target){
            // if l == 0, it means that sum of all elements was still less than target. i.e. output 0
            if (l == 0){
                return 0;
            }
            else{
                return minlen;
            }
        }

        // we set pointers l, r.
        // We enlarge r while the sum btw l, r is less than target.
        // if the sum is more than target, we increase l until it's no longer so. everytime increase l do this, we see if the range l, r is the minimum found so far.
        if (sum < target){
            sum += nums[++r];
        }
        else{
            minlen = (minlen < (r-l+1)) ? minlen : (r-l+1);
            sum -= nums[l++];
        }
    }
}