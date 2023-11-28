//
// Created by Gun woo Kim on 11/23/23.
//
#include <vector>
#include <algorithm>
using namespace std;

int guess(int n) {
    // temprarily made dummy function.
    // no use.
    return 0;
}

int guessNumber(int n) {
    long int l = 0, r = n, mid = 0;
    int response = 0;

    while (l <= r){
        mid = (l+r) / 2;
        response = guess(mid);

        if (response == 0){
            return mid;
        }
        else if (response == 1){
            l = mid + 1;
        }
        else if (response == -1){
            r = mid - 1;
        }
    }
    return -1;
}