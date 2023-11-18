//
// Created by Gun woo Kim on 11/17/23.
//
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size(); i++){
        if (nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}