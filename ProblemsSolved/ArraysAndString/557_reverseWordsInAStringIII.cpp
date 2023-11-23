//
// Created by Gun woo Kim on 11/22/23.
//
#include <string>
using namespace std;

string reverseWordsIII(string s) {
    int l = 0, r = 0;
    for (; r < s.size(); r++){
        if (r == s.size()-1 || s[r+1] == ' '){
            reverse(s.begin()+l, s.begin()+r+1);
            l = r+2;
        }
    }
    return s;
}