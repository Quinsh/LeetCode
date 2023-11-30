//
// Created by Gun woo Kim on 11/28/23.
//
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, int> s_hash, t_hash;
    for (int i = 0, order_s = 0, order_t = 0; i < s.size(); i++){
        if (s_hash.count(s[i]) <= 0){
            s_hash[s[i]] = order_s++;
        }
        if (t_hash.count(t[i]) <= 0){
            t_hash[t[i]] = order_t++;
        }
    }
    for (int i = 0; i < s.size(); i++){
        if (s_hash[s[i]] != t_hash[t[i]]){
            return false;
        }
    }
    return true;
}