//
// Created by Gun woo Kim on 11/27/23.
//
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> uniquenums;
    for (int &n : nums){
        if (uniquenums.count(n) > 0){
            return true;
        }
        uniquenums.insert(n);
    }
    return false;
}