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
#include <cmath>
#include <iostream>

using namespace std;

/**
 * DATE: 2024.07.01 
 * INTUITION: for 1 : sqrt(n), we check if there is a `b` with binary search.
 * 
 * TC: O(nlogn) with n = sqrt(c)
 * SC: O(1)
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);

        for (int a = 0; a <= n; a++) {
            int l = 0, r = n, mid;
            int aa = a*a;
            
            while (l <= r) {
                mid = l + (r-l)/2;
                int bb = mid*mid;
                if (bb == c - aa) {
                    return true;
                }
                else if (bb < c - aa)
                    l = mid+1;
                else if (bb > c - aa)
                    r = mid-1;
            }
        }
        return false;
    }
};