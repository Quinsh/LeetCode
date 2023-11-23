//
// Created by Gun woo Kim on 11/18/23.
//
#include <vector>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    int s = needle.size();

    if (haystack.size() < needle.size()){
        return -1;
    }

    for (int i = 0; i <= haystack.size() - s; i++){
        for (int h = i, n = 0; h < i+s ; h++){
            if (haystack[h] != needle[n++]) break;

            if (h == i+s-1) return i;
        }
    }
    return -1;
}