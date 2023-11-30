//
// Created by Gun woo Kim on 11/28/23.
//
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++){
        if (hashmap.count(nums[i]) > 0){
            if (abs(i - hashmap[nums[i]]) <= k){
                return true;
            }
        }
        hashmap[nums[i]] = i;
    }
    return false;
}