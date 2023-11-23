//
// Created by Gun woo Kim on 11/22/23.
//
#include <vector>
#include <string>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> pascal = {1};
    int temp;
    for (int i = 2; i <= rowIndex+1; i++){
        int saved = pascal[0];
        for (int j = 1; j < i-1; j++){
            temp = pascal[j];
            pascal[j] += saved;
            saved = temp;
        }
        pascal.push_back(1);
    }
    return pascal;
}