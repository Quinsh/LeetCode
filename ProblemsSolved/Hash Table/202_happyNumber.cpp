//
// Created by Gun woo Kim on 11/27/23.
//
#include <unordered_set>
#include <vector>
using namespace std;

int _202compute(int n){
    if (n == 0) return 0;
    else{
        int lastdigit = n % 10;
        return lastdigit * lastdigit + _202compute(n/10);
    }
}
bool isHappy(int n) {
    unordered_set<int> s;
    while(n != 1){
        if (s.count(n) == 1){
            return false;
        }
        s.insert(n);
        n = _202compute(n);
    }
    return true;
}