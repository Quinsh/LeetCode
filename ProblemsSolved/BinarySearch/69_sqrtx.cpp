//
// Created by Gun woo Kim on 11/23/23.
//
#include <vector>
#include <algorithm>
using namespace std;

// maybe instead of mid*mid < x,
// doing mid < x/mid can be advantageous.
// it can use less memory..? can be faster..?
int mySqrt(int x) {
    long int l = 0, r = x, mid = 0;
    while (l <= r){
        mid = (l+r) / 2;
        if (mid*mid == x){
            return mid;
        }
        else if (mid*mid < x){
            l = mid + 1;
        }
        else if (mid*mid > x){
            r = mid - 1;
        }
    }
    return r;
}