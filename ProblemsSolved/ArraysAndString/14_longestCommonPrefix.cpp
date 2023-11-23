//
// Created by Gun woo Kim on 11/18/23.
//
#include <string>
#include <vector>
using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1){
        return strs[0];
    }

    int min = strs[0].size();
    for (int i = 1; i < strs.size(); i++){
        min = (min < strs[i].size()) ? min : strs[i].size();
    }

    for (int i = 0; i < min; i++){
        for (int j = 1; j < strs.size(); j++){
            if (strs[j-1][i] != strs[j][i]){
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0].substr(0, min);
}

// smarter solution:
// if we sort the list, it sorts in alphabetical order
// then, we just need to compare two (first and last) every index because
// the things in the middle are all good if the first and last are good.

string longestCommonPrefix_alt(vector<string>& v) {
    string ans="";
    sort(v.begin(),v.end());
    int n=v.size();
    string first=v[0],last=v[n-1];
    for(int i=0;i<min(first.size(),last.size());i++){
        if(first[i]!=last[i]){
            return ans;
        }
        ans+=first[i];
    }
    return ans;
}