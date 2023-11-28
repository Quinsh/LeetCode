//
// Created by Gun woo Kim on 11/26/23.
//
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> res;
    for (auto a : nums2)
        if (m.count(a)) {
            res.push_back(a);
            m.erase(a);
        }
    return res;
}