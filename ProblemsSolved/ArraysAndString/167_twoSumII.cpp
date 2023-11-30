//
// Created by Gun woo Kim on 11/19/23.
//
#include <vector>
#include <string>
using namespace std;

vector<int> twoSumII(vector<int>& numbers, int target) {
    // we can iterate l from 0 to end;
    // for each iteration on l, we just need to see if num[l] + num[r] is less than target,
    // because if it is, we don't need to sum num[l] with other numbers at right (since the array is sorted)
    // if num[l] + num[r] is more than target, we have found the correct 'l' and we now iterate to find the r.
    int l = 0;
    int r = numbers.size()-1;
    vector<int> result;

    for (; l < numbers.size(); l++){
        for (; r > l; r--){
            if (numbers[l] + numbers[r] < target){
                break;
            }
            else if (numbers[l] + numbers[r] == target){
                result.push_back(l+1);
                result.push_back(r+1);
            }
        }
    }
    return result;
}