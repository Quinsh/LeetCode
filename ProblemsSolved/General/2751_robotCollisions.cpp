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
 * DATE: 2024.07.13
 * INTUITION: we can use stack as we iterate in the array of robots (sorted on their positions)
 * 
 * TC: O(NlogN) - for sorting
 * SC: O(N) to construct the array.
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        // create the array used.
        vector<vector<int>> robots;
        for (int i = 0; i < positions.size(); i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        // sort the array based on their position O(NlogN)
        const auto cmp = [](vector<int>& v1, vector<int>& v2) {
            return v1[0] < v2[0];
        };
        sort(robots.begin(), robots.end(), cmp);
        
        // iterate through the array with stack
        stack<vector<int>> movingright;
        vector<vector<int>> ans;
        for (int i = 0; i < robots.size(); i++) {
            
            if(robots[i][2] == 'L') {
                while (!movingright.empty() && robots[i][1] > 0) {
                    if (movingright.top()[1] > robots[i][1]) {
                        movingright.top()[1]--; robots[i][1] = 0;
                    }
                    else if (movingright.top()[1] < robots[i][1]) {
                        movingright.pop(); robots[i][1]--;
                    }
                    else {
                        movingright.pop(); robots[i][1] = 0;
                    }
                }
                // if robot survived after all that (which means the stack is empty), push that to the answer.
                if (robots[i][1] > 0) ans.push_back({robots[i][1], robots[i][3]});
            }
            else {
                movingright.push(robots[i]);
            }
        }
        // add things left at the end to the answer vector
        while(!movingright.empty()) {
            ans.push_back({movingright.top()[1], movingright.top()[3]}); movingright.pop();
        }
        const auto cmp2 = [](vector<int> &v1, vector<int> &v2) {return v1[1] < v2[1];};
        sort(ans.begin(), ans.end(), cmp2);
        vector<int> ansInOrder;
        for (const auto &x : ans) {
            ansInOrder.push_back(x[0]);
        }
        return ansInOrder;
    }
};