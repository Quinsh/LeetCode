//
// Created by Gun woo Kim on 11/23/23.
//
#include <vector>
using namespace std;

int binSearch(vector<int>& nums, int target, int l, int r){
    int mid = (l+r) / 2;
    if (l <= r){
        if      (nums[mid] == target) return mid;
        else if (nums[mid] <  target) return binSearch(nums, target, l+1, r);
        else if (nums[mid] >  target) return binSearch(nums, target, l, r-1);
    }
    return -1;
}