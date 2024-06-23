#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

/**
 * DATE: 2024.06.21
 * INTUITION: Do one pass bfs by putting every 0s in the queue when beginning. Then, for the adjacent nodes, 
 * if it's higher than the current node, we substitute its value by current node + 1 (bcz it means that it can be reached from the current node) 
 * and add it to the queue (to start bfs from there later).
 * 
 * TC: O()
 * SC: O(mn)
 * 
 * TOIMPROVE: 
*/
class Solution541 {
private:
    vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0, -1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] = INT_MAX;
                }
                else {
                    q.emplace(i, j);
                }
            }
        }
        
        // Start BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (const auto &dir : directions) {
                int new_x = x + dir.first;
                int new_y = y + dir.second;

                if (new_x >= 0 && new_y >= 0 && new_x < mat.size() && new_y < mat[0].size()) {
                    if (mat[new_x][new_y] > mat[x][y] + 1) {
                        mat[new_x][new_y] = mat[x][y] + 1;
                        q.emplace(new_x, new_y);
                    }
                }
            }
        }
        return mat;
    }
};
