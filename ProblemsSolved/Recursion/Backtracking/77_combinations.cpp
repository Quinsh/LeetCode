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
 * DATE: 2024.07.22
 * INTUITION: Let's do backtracking.
 * we can't have [1,2] and [2,1] at the same time, since there's no way of knowing if we should continue or not at the point of [2, ?],
 * let's just choose to store the built array into answer or not at the end of the recursion. For this, let's use a set of sum of numbers to see if that array alrdy exists.
 * For example, [1,2] = 3, [2,1] = 3, so if we end up building [2,1] we don't add it to the answer.
 * Ok, we can keep a variable `sum_left` that is the sum of elements left in the build_set. If the sum of current array + sum_left is already in the check_set, we backtrack.
 * No, this doesn't work, since this would classify [1,4] same as [2,3] in a range of (1,2,3,4) and then not build [2,3]
 * 
 * Ok I see a pattern now. 1-2, 1-3, 1-4,  2-3, 2-4,  3-4  OK lol
 * 
 * TC: 
 * SC: O(n*k) - I'm copying buildset every recursion.
 * 
 * TOIMPROVE: Oh, we could just pass a integer to iterate in a for loop rather than a buildset. Since it's just sorted numbers. and pass num+1 recursively.
 */
class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> range(n);
        iota(range.begin(), range.end(), 1);
        set<int> buildset;
        buildset.insert(range.begin(), range.end());
        vector<int> temp;
        build(buildset, temp, 0, k);
        return ans;
    }

    void build(set<int> buildset, vector<int> &vec, int cur, int k) {
        if (cur == k) {
            ans.push_back(vec);
            return;
        }
        
        for (auto it = buildset.begin(); it != buildset.end(); ) {
            vec.push_back(*it);
            it = buildset.erase(it); // erase the cur element and get the iterator to the next element
            
            build(buildset, vec, cur+1, k);
            vec.pop_back(); 

        }
    }
};