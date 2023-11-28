//
// Created by Gun woo Kim on 11/23/23.
//
#include <vector>
using namespace std;

// we need to understand that the rotated part is the minimum.
// e.g: 5 1 2 3 4. 1 is the minimum where it is rotated.

int findMinimumInRotatedSortedArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r){
            int mid = (l+r) / 2;
            // if nums[mid] < nums[r], the rotated part is possibly nums[mid] or somewhere in the left side.
            if (nums[mid] < nums[r])    r = mid;
            // if nums[mid] > nums[r], the left side is just continuous (like 5 6 7) and the right side contains the rotated part
            else                        l = mid+1;
        }
        return nums[l];
    }
