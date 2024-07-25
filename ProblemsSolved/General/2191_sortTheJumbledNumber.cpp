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
 * DATE: 2024.07.24
 * INTUITION:
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const auto cmp = [&](const int &a, const int &b){
            int aa = parse(mapping, a);
            int bb = parse(mapping, b);
            return aa < bb;
        };
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }

    int parse(vector<int> &mapping, int n) {
        int x = mapping[n%10]; n /= 10;
        int index = 10;
        while (n) {
            int d = n%10;
            int x_d = mapping[d];
            x += x_d * index;
            index *= 10;
            n /= 10;
        }
        return x;
    }
};