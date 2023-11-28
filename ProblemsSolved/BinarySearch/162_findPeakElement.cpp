//
// Created by Gun woo Kim on 11/23/23.
//
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    // when there is only 1 element
    if (r == 0){
        return 0;
    }
    // when there is 2 elements
    if (r == 1){
        return (nums[0] > nums[1]) ? 0 : 1;
    }
    // when there is 3+ elements
    while (l < r-1){
        int mid = l + (r-l)/2;
        if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            return mid;
        }
            // else if the mid-1'th number is greater, move to that side
        else if (nums[mid] < nums[mid-1]){
            r = mid;
        }
            // else, the number right to mid is greater than mid
        else{
            l = mid;
        }
    }
    return (nums[l] > nums[r]) ? l : r;
}

/* another appraoch
int recursive_binary_search(vector<int>& nums, int low, int high){
    if(low == high){
        return low;
    }
    int mid = (low + high) >> 1;
    if(nums[mid] > nums[mid+1]){
        return recursive_binary_search(nums, low, mid);
    }
    else{
        return recursive_binary_search(nums, mid+1, high);
    }
}
int findPeakElement(vector<int>& nums) {
    return recursive_binary_search(nums, 0, nums.size()-1);
}
*/

/* Another logical approach
int findPeakElement(vector<int>& nums) {

    if(nums.length == 1) return 0; // single element

    int n = nums.length;

    // check if 0th/n-1th index is the peak element
    if(nums[0] > nums[1]) return 0;
    if(nums[n-1] > nums[n-2]) return n-1;

    // search in the remaining array
    int start = 1;
    int end = n-2;

    while(start <= end) {
        int mid = start + (end - start)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
        else if(nums[mid] < nums[mid-1]) end = mid - 1;
        else if(nums[mid] < nums[mid+1]) start = mid + 1;
    }
    return -1; // dummy return statement
}
*/