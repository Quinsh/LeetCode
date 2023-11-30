//
// Created by Gun woo Kim on 11/28/23.
//
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> hashmap;
    vector<vector<string>> res;
    int resIndex = 0;
    for (string &s : strs){
        string key = s;
        sort(key.begin(), key.end());
        if (hashmap.count(key) <= 0){
            hashmap.insert(make_pair(key, resIndex));
            res.push_back({s});
            resIndex++;
        }
        else{
            res[hashmap[key]].push_back(s);
        }
    }
    return res;
}