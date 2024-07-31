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
 * DATE: 2024.07.26
 * INTUITION: store words in a map with keys being the length of the word.
 * Then, do a 1d dp that returns true if any of the recursive wordBreak after partitioning returns true.
 * Ex: "leetcode" should return true because "leet" + wordBreak("code") works, where wordBreak("code") returns true.
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    int r;
    vector<int> cache;
    unordered_map<int, vector<string>> stringmap;
    string fullword;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (const auto &word: wordDict)
            stringmap[word.size()].push_back(word);

        r = s.size();
        cache.resize(r, -1);
        fullword = s;
        return dp(0);
    }

    bool dp(int l) {
        if (l==r) return true;
        if (cache[l] == -1) {
            for (const auto &pair : stringmap) {
                int wsize = pair.first;
                for(const auto &word : pair.second) {
                    if ((fullword.substr(l, wsize) == word) && dp(l+wsize)) {
                        cache[l] = 1;
                    }
                }
            }
            cache[l] = 0;
        }
        return cache[l];
    }
};