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
 * DATE: 2024.06.30
 * INTUITION: A - a + b = B - b + a  =>  a = b (A-B)/2
 * 
 * TC: O(A + B)
 * SC: O(B)
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        unordered_set<int> B(bobSizes.begin(), bobSizes.end());
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int middiff = abs(sumA - sumB) / 2;

        for (const auto &a : aliceSizes) {
            int b = a + middiff;
            if (B.find(b) != B.end()) {
                return {a, b};
            }
        }
    }
};