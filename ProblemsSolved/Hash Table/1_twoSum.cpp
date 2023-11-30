//
// Created by Gun woo Kim on 11/27/23.
//
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++){
        int comp = target - nums[i];
        if (hashmap.count(comp) > 0){
            res = {hashmap[comp], i};
            return res;
        }
        hashmap[nums[i]] = i;
    }
    return res;
}