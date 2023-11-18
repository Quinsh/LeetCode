//
// Created by Gun woo Kim on 11/17/23.
//

#include <vector>
using namespace std;

vector<int> diagonalTraverse(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int n_diag = (m-1 + n-1 + 1);
    vector<int> diag_length(n_diag, 0);
    vector<int> result(m*n, 0);
    int index = 0;

    { // make a list of diagonal lengths like [1, 2, 3, 2, 1]
        int d = min(m, n);
        for (int s = 0; s < n_diag; s++){
            if (s < d){
                diag_length[s] = s+1;
            }
            else if (s < n_diag - d + 1){
                diag_length[s] = d;
            }
            else{
                diag_length[s] = n_diag - s;
            }
        }
    }

    for (int s = 0; s < n_diag; s++){
        if (s%2 == 0){ // we are crossing leftbottom to righttop
            int i = min(m-1, s);
            int j = s - i;
            for (int k = 0; k < diag_length[s]; k++){
                result[index++] = mat[i][j];
                i--; j++;
            }
        }
        else{ // crossing righttop to leftbottom
            int j = min(n-1, s);
            int i = s - j;
            for (int k = 0; k < diag_length[s]; k++){
                result[index++] = mat[i][j];
                i++; j--;
            }
        }
    }

    return result;
}