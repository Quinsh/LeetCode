//
// Created by Gun woo Kim on 11/27/23.
//
#include <unordered_set>
#include <vector>
using namespace std;
// many people are using ^= . see other solutions
int singleNumber(vector<int>& nums) {
    unordered_set<int> uniquenums;
    for (int &n : nums){
        if (uniquenums.count(n) == 1){
            uniquenums.erase(n);
        }
        else{
            uniquenums.insert(n);
        }
    }
    return *(uniquenums.begin());
}