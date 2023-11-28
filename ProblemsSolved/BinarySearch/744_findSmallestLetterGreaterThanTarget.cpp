//
// Created by Gun woo Kim on 11/25/23.
//
#include <vector>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int l = 0, r = letters.size()-1;
    while (l < r){
        int mid = l + (r-l)/2;
        if (letters[mid] <= target) l = mid + 1;
        else r = mid;
    }
    // l is unchecked
    if (letters[l] <= target) return letters[0];
    return letters[l];
}
