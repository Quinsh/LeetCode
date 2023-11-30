//
// Created by Gun woo Kim on 11/28/23.
//
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> hashmap1, hashmap2;
    vector<int> res;
    for (int i = 0; i < nums1.size(); i++){
        if (hashmap1[nums1[i]]) hashmap1[nums1[i]] += 1;
        else hashmap1[nums1[i]] = 1;
    }

    for (int i = 0; i < nums2.size(); i++){
        if (hashmap2[nums2[i]]) hashmap2[nums2[i]] += 1;
        else hashmap2[nums2[i]] = 1;

        if (hashmap1.count(nums2[i]) > 0 &&
            hashmap2[nums2[i]] <= hashmap1[nums2[i]]){
            res.push_back(nums2[i]);
        }
    }
    return res;
}