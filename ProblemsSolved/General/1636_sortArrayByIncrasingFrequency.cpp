#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
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
 * DATE: 2024.07.23
 * INTUITION: store in a map and use that as a comparator
 * 
 * TC: O(NlogN)
 * SC: O(N)
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map;
        for (const auto &n : nums) {
            map[n]++;
        }
        const auto cmp = [&map](int &a, int &b) {
            if (map[a]==map[b]) return a > b;
            else return map[a] < map[b];
        };
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};