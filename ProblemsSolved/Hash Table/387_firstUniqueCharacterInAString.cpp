//
// Created by Gun woo Kim on 11/28/23.
//
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> hashmap;
    for (int i = 0; i < s.size(); i++){
        if (hashmap.count(s[i]) > 0){
            hashmap[s[i]] += 1;
        }
        else{
            hashmap[s[i]] = 1;
        }
    }
    for (int i = 0; i < s.size(); i++){
        if (hashmap[s[i]] == 1) return i;
    }
    return -1;
}