//
// Created by Gun woo Kim on 11/23/23.
//
#include <vector>
using namespace std;

// just a dummy function
bool isBadVersion(int n){
    return true;
}

int firstBadVersion(int n) {
    long int l = 1, r = n;
    while (l < r){
        int mid = (l+r) / 2;
        bool bad = isBadVersion(mid);
        if (bad) {
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return l;
    // "l" will always be the bad, because at the end of the loop, l == r and r is the last thing that was bad.
}