//
// Created by Gun woo Kim on 11/17/23.
//
#include <vector>
#include <math.h>
using namespace std;

vector<int> squaresOfASortedArray(vector<int>& nums) {

    vector<int> sortedArr(nums.size());
    int l = 0, r = nums.size() - 1;

    for(int i = nums.size() - 1; i >= 0; i--){
        if(abs(nums[r]) > abs(nums[l])){
            sortedArr[i] = pow(nums[r--], 2);
        }
        else{
            sortedArr[i] = pow(nums[l++], 2);
        }
    }

    return sortedArr;
}