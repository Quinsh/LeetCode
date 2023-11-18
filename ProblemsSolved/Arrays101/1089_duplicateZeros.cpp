//
// Created by Gun woo Kim on 11/17/23.
//
#include <vector>
using namespace std;

void duplicateZeros(vector<int>& arr) {
    int n = arr.size(), j = n + count(arr.begin(), arr.end(), 0);

    for(int i = n-1; i >= 0; i--){
        // decrease j
        j--;

        // if j is inside the size of array
        if(j < n){
            // put thing in pos i to pos j.
            arr[j] = arr[i];
        }

        // if that thing is 0, decrease j and put one more 0 in pos j.
        if(arr[i] == 0 && --j < n){
            arr[j] = 0;
        }
    }
}