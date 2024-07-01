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
 * DATE: 2024.07.01
 * INTUITION: sliding window O(n)
 * 
 * TC: O(n)
 * SC: O(1)
 * 
 * TOIMPROVE: 
*/
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consecutive = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] & 1) consecutive++;
            else consecutive--;

            if (consecutive == 3) 
            return true;
        }
        return false;
    }
};