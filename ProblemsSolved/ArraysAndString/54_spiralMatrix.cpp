//
// Created by Gun woo Kim on 11/17/23.
//
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // 4 pointers approach
    int left = 0, right = matrix[0].size()-1;
    int top = 0, bottom = matrix.size()-1;
    int index = 0;
    int len = (right+1)*(bottom+1);
    vector<int> result;

    while (left <= right && top <= bottom){
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        } top++;
        for (int i = top; i <= bottom; i++){
            result.push_back(matrix[i][right]);
        } right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--){
                result.push_back(matrix[bottom][i]);
            } bottom--;
        }
        if (left <= right){
            for (int i = bottom; i >= top; i--){
                result.push_back(matrix[i][left]);
            } left++;
        }
    }
    return result;
}