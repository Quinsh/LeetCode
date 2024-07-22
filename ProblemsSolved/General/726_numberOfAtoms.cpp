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
 * DATE: 2024.07.14
 * INTUITION: use a stack of map to store elements in each bracket level and multiply every elements by number when we find a `)`
 * 
 * TC: O(N) 
 * SC: O(N)
 * 
 * TOIMPROVE: 
 */
class Solution {
public:
    string countOfAtoms(string formula) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        stack<map<string, int>> s; // map stores the element : count
        map<string, int> start;
        s.push(start);
        
        for (int i = 0; i < formula.size(); i++) {
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                if (formula[i+1] >= 'a' && formula[i+1] <= 'z') continue;
                if (formula[i+1] >= '1' && formula[i+1] <= '9') continue;
                string key = formula.substr(i, 1);
                s.top()[key] += 1;
            }
            else if (formula[i] >= 'a' && formula[i] <= 'z') {
                if (formula[i+1] >= '1' && formula[i+1] <= '9') continue;
                string key = formula.substr(i-1, 2);
                s.top()[key] += 1;
            }
            else if (formula[i] >= '1' && formula[i] <= '9') {
                int len = 1;
                while (formula[i+len] >= '0' && formula[i+len] <= '9') len++;
                int numb = stoi(formula.substr(i, len));

                if (formula[i-1] == ')') {
                    map<string, int> curmap = s.top(); s.pop();
                    // for everything in the map multiply by number and add it to the top:
                    for (const auto &pair : curmap) {
                        int val = pair.second * numb;
                        s.top()[pair.first] += val;
                    }
                }
                else {
                    string key = "";
                    if (formula[i-1] >= 'a' && formula[i-1] <= 'z') {
                        key = formula.substr(i-2, 2);
                    }
                    else key = formula.substr(i-1, 1);
                    s.top()[key] += numb;
                    
                }
                i += len-1;
            }
            else if (formula[i] == '(') {
                map<string, int> newmap;
                s.push(newmap);
            }
            else if (formula[i] == ')' && !(formula[i+1] >= '1' && formula[i+1] <= '9')) {
                map<string, int> curmap = s.top(); s.pop();
                // for everything in the map multiply by number and add it to the top:
                for (const auto &pair : curmap) {
                    s.top()[pair.first] += pair.second;
                }
            }
        }
        string ans = "";
        for (const auto &pair : s.top()) {
            ans += pair.first;
            if (pair.second != 1) ans += to_string(pair.second);
        }
        return ans;
    }
};