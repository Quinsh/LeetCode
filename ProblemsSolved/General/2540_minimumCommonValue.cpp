#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

/**
 * DATE: 2024.06.29
 * INTUITION: O(N+M) solution where we use two pointers.
 * 
 * TC: O(N+M)
 * SC: O(1)
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        while(i < n && j < m) {
            if (nums1[i] == nums2[j]) return nums1[i];

            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
        }
        return -1;
    }
};
