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
 * DATE: 2024.06.23
 * INTUITION: store index:cnt pair in a map. make a heap of indexes with custom comparator that uses the cnt.
 * 
 * TC: O(MN + KlogN) - O(MN) for making the map, O(N) for making the heap, O(KlogN) to pop the answer.
 * SC: O(N) - where N is the num rows.
 * 
 * TOIMPROVE: we can actually use binary search to find the 1s (because they are in sorted order)
*/
class Solution1337 {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        // O(MN) for counting the 1s in the matrix
        unordered_map<int, int> rowcount;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) break;
                rowcount[i]++;
            }
        }

        // make a custom comparator
        auto cmp = [&rowcount](int a, int b) {
            if (rowcount[a] == rowcount[b]) {
                return a > b;
            }
            else {
                return rowcount[a] > rowcount[b];
            }
        };

        // make a heap of row indexes that uses the custom comparator. 
        vector<int> range(mat.size());
        iota(range.begin(), range.end(), 0);
        priority_queue<int, vector<int>, decltype(cmp)> minheap(cmp, range); // we create a `range` vector which is just the vector 0 to max row index. 

        // pop the results into the answer vector
        vector<int> answer;
        for (int i = 0; i < k; i++) {
            answer.push_back(minheap.top());
            minheap.pop();
        }

        return answer;
    }
};