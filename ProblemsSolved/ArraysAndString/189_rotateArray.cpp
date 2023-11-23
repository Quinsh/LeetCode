//
// Created by Gun woo Kim on 11/22/23.
//
// This problem brought me pain.
// Try looking at different solutions, because I think this way is not the intended one by problem creator.
class Solution {
public:
    void rotate(vector<int>& nums, int k){
        int n = nums.size();
        k = k%n;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};

