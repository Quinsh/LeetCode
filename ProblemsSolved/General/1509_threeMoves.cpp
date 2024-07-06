
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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define btoe(x) (x).begin(), (x).end()
#define pb push_back

const int INF = 1e9;
const int MOD = 1e9 + 7;

/**
 * DATE: 2024.07.03
 * INTUITION: greedily delete the leftmost or rightmost element of the sorted array.
 * when to delete the leftmost/rightmost?
 * when we have 3 moves, consider if deleting the lowest 3, or highest 3 would be better
 * when we have 2 moves, consider if deleting the lowest 2, or highest 2 would be better
 * when we have 1 move,  consider if deleting the lowest or highest would be better.
 * `better` means ofc the least difference btw lowest and highest.
 * 
 * TC: O(nlogn) - for sorting. 
 * SC: O(n)
 * 
 * TOIMPROVE: we can use partial sorting. Discover how to do this. 
 */

class Solution {
public:
    int minDifference(vector<int>& nums) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        if (nums.size() <= 3) return 0;

        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;

        for (int i=3; i>0; i--) {
            int new_l = l + i;
            int new_r = r - i;
            if (nums[r] - nums[new_l] < nums[new_r] - nums[l]) 
                l++;
            else
                r--;
        }

        return nums[r] - nums[l];
    }
};