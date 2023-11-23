//
// Created by Gun woo Kim on 11/19/23.
//
#include <vector>
#include <string>
using namespace std;

int arrayPartition(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int sum = 0;
    for (int i = 0; i < nums.size(); i+=2){
        sum += nums[i];
    }
    return sum;
}