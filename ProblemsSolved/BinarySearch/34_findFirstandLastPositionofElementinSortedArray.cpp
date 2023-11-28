//
// Created by Gun woo Kim on 11/24/23.
//
#include <vector>
using namespace std;

vector<int> findFirstAndLastPos(vector<int>& nums, int target) {
    // if it's empty,
    if (nums.size() == 0){
        vector<int> res = {-1, -1};
        return res;
    }

    // search left range first
    int l = 0, r = nums.size()-1;
    int leftrange = 0;
    while (l < r){
        int mid = (l+r)/2;
        if (nums[mid] >= target) r = mid;
        else l = mid+1;
    }
    if (nums[l] != target) leftrange = -1;
    else leftrange = l;

    // search right range first
    l = 0, r = nums.size()-1;
    int rightrange = 0;
    while (l < r){
        int mid = (l+r+1)/2;
        if (nums[mid] <= target) l = mid;
        else r = mid-1;
    }
    if (nums[l] != target) rightrange = -1;
    else rightrange = l;

    // print answer
    vector<int> res = {leftrange, rightrange};

    return res;
}