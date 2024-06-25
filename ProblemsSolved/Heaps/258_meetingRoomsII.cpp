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
 * DATE: 2024.06.25
 * INTUITION: I can think of a brute force approach that will terribly run out of time. Otherwise, have no idea. Oh wait. It got accepted lol.
 * If there were more edge test cases, it would have ran out of time for sure.
 * 
 * TC: O(wtf)
 * SC: O(10^6)
 * 
 * TOIMPROVE: learn the heap approach.
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> times;
        times.resize(1000000);
        
        for (const auto &interval : intervals) {
            int a = interval[0]; int b = interval[1];
            for (int i = a; i < b; i++) {
                times[i]++;
            }
        }

        return *max_element(times.begin(), times.end());
    }
};