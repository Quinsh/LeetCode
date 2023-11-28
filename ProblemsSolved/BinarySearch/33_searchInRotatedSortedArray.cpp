//
// Created by Gun woo Kim on 11/23/23.
//
#include <vector>
using namespace std;

int binSearch(vector<int>& nums, int target, int l, int r);

int searchRotatedSortedArray(vector<int>& nums, int target) {
    // "possibly" rotated. So find the point where it is rotated.
    // maybe do Binary Search twice or re-rotate the array.
    // let's do binary search twice because re-rotating array is easy solution.

    // first find the position where it is rotated.
    int start = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            start = i;
        }
    }


    int firstSearch = binSearch(nums, target, 0, start-1);
    // if it was not found on first search,
    if (firstSearch == -1){
        int secondSearch = binSearch(nums, target, start, nums.size()-1);
        return secondSearch;
    }
    return firstSearch;
}
