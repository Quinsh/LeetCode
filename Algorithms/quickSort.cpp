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
 * DATE: 2024.07.19
 * INTUITION: QUICKSORT ALGORIHTM IMPLEMENTATION
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
 */
void quickSort(vector<int> &nums) {
    qSort(nums, 0, nums.size()-1);
}

void qSort(vector<int> &nums, int l, int r) {
    if (l < r) {
        int p = partition(nums, l, r);
        qSort(nums, l, p-1);
        qSort(nums, p+1, r);
    }
}

int partition(vector<int> &nums, int l, int r) {
    int pivot = r;
    int lower = l;
    for (int i = l; i < r; i++) {
        if (nums[i] <= nums[pivot]) {
            swap(nums[i], nums[lower++]);
        }
    }
    swap(nums[pivot], nums[lower]);
    return lower;
}
