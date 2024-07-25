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
 * INTUITION:
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    map<char, string> mapping = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return {};
        string temp = "";
        backtracking(0, digits.size(), temp, digits);
        return ans;
    }

    void backtracking(int k, int n, string temp, string digits) {
        if (k == n) {
            ans.push_back(temp);
            return;
        }
    
        for (const auto &c : mapping[digits[k]]) {
            temp += c;
            backtracking(k+1, n, temp, digits);
            temp.pop_back();
        }
    } 
};