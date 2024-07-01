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
#include <random>

using namespace std;

/**
 * DATE: 2024.06.30
 * INTUITION: just pick a random number btw 0 and arraysum, and return the index where that random value should lie in the cumulative array.
 * 
 * TC: O(n) for iterating
 * SC: O(1) - didn't use anything.
 * 
 * TOIMPROVE: can implement binary search here instead of iterating, obviously.
*/
class Solution {
private:
    vector<int> data;
    random_device rd;
    mt19937 gen;
    uniform_real_distribution<> distr;
public:
    Solution(vector<int>& w) : data(w), gen(rd) {
        int sum = accumulate(w.begin(), w.end(), 0);
        distr = uniform_real_distribution<>(0, sum);
    }
    
    int pickIndex() {
        double rand = distr(gen);
        double acc = 0;

        for (int i = 0; i < data.size(); i++) {
            acc += data[i];
            if (acc >= rand) {
                return data[i];
            }
        }
    }
};
