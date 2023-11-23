//
// Created by Gun woo Kim on 11/18/23.
//
#include <vector>
using namespace std;

vector<vector<int>> pascalsTriangle(int numRows) {
    vector<vector<int>> pascal = {{1}};

    if (numRows >= 2){
        pascal.push_back({1, 1});
    }
    if (numRows >= 3){
        for (int i = 2; i <= numRows-1; i++){
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j <= pascal[i-1].size()-1; j++){
                temp.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
            }
            temp.push_back(1);

            pascal.push_back(temp);
        }
    }
    return pascal;
}

// other smart solution that I found:
vector<vector<int>> pascalsTriangle_alt(int numRows) {
    vector<vector<int>> v(numRows); // vector inside vector(if we take vector of vector we need to mention size)
    for (int i = 0; i < numRows; i++) {
        v[i].resize(i + 1);
        v[i][0] = v[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }
    return v;
}