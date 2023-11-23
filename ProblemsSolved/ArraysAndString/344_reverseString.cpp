//
// Created by Gun woo Kim on 11/19/23.
//
#include <vector>
#include <string>
using namespace std;

void reverseString(vector<char>& s) {
    int i = 0, j = s.size()-1;
    while (i < j){
        swap(s[i++], s[j--]);
    }
}