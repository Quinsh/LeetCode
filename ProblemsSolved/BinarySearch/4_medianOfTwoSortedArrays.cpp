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
 * DATE: 2024.07.02
 * INTUITION: O(m+n) approach: iterate with two pointers (m+n)/2 times.
 * O(log(m+n)) approach: ?
 * 
 * [1,3] [2] -> 2
 * [1,2] [3,4] -> 2.5
 * 
 * binary search considering two arrays as one? --> then we need to know the point the connection point btw two arrays. [1,3] [2,4] actually no. it can't be considered as one array without directly being merged with O(n+m)
 * we consider two arrays separately? --> we do one binary search but alternating arrays. Our objective is to find the number with the middle index. This can be either in the first array, second array or both (if m+n is even).
 * 
 * 
 * TC: O(log(m+n))
 * SC: 
 * 
 * TOIMPROVE: 
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        
        



    }
};