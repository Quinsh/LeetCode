#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * DATE: 06.17.2024
 * INTUITION: use stack and iterate from back to beginning. As we iterate:
 * 1. if top() is higher than the number, answer is 1.
 * 2. if top() is lower than then number, we pop() until we find a top() higher than the number (the sum of answer for those we popped + 1 becomes the answer).
 *      If we can't find a top() higher than the number, answer is 0.
 * 
 * wow it was a bit hard to come up with this one. took like 20 mins to think. 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: Ok. My code was pretty complex. Not the "standard way to solve this". Let's see the editorial as well and study abt "monotonic stack"
*/
vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> pairstack; // stack of <value, answer> pair
        vector<int> ans;
        int len = temperatures.size();
        ans.resize(len);
        ans[len-1] = 0; // the last index will always be 0.
        pairstack.emplace(temperatures[len-1], 0);

        // iterate from the second number in the back to front
        for (int i = temperatures.size()-2; i >= 0; i--) {
            int cnt = 1;
            int topval, topans = 0;
            do {
                cnt += topans;
                if (pairstack.empty()) {
                    // popped everything and still not found top() bigger than current number. So zero cnt.
                    cnt = 0;
                    break;
                }
                topval = pairstack.top().first;
                topans = pairstack.top().second;
                
                if (topval <= temperatures[i]) pairstack.pop();
            }
            while (topval <= temperatures[i]);

            pairstack.emplace(temperatures[i], cnt);
            ans[i] = cnt;
        }
        return ans;
    }