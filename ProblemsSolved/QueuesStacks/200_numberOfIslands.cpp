#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

/**
 * INTUITION: for every cell, do bfs if it hasn't been visited. For each newly visiting land, do cnt++.
 * 
 * TOIMPROVE: ohh, I can just mark them as '0'. No need to use sets.
 * 
*/
int numIslands(vector<vector<char>>& grid) {
    vector<pair<int, int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    int count = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {

            if (grid[i][j] == '0') continue;

            // do all the BFS to mark all the connecting lands as visited
            queue<pair<int, int>> q;
            q.emplace(i, j);
            while (!q.empty()) {
                auto [cur_i, cur_j] = q.front();
                q.pop();

                for (const auto &dir : directions) {
                    int x = cur_i + dir.first, y = cur_j + dir.second;
                    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0') continue;
                    if (grid[x][y] == '0') continue; 

                    grid[x][y] = '0';
                    q.emplace(x,y);
                }
            }
            // discovered new land!
            count++;
        }
    }

    return count;
}


/**
 * DATE: 2024.06.18
 * INTUITION: same thing but use dfs this time
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
*/
int numIslands2(vector<vector<char>>& grid) {
    int cnt = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                DFS(grid, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

void DFS(vector<vector<char>> &grid, int i, int j) {
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    stack<pair<int, int>> stack;
    stack.emplace(i, j);
    grid[i][j] = '0';

    auto isValid = [&grid](int i, int j) {
        return (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size());
    };

    while (!stack.empty()) {
        pair<int, int> curpos = stack.top();
        grid[curpos.first][curpos.second] = '0';
        stack.pop();

        for (const auto &dir : directions) {
            int next_x = curpos.first + dir.first;
            int next_y = curpos.second + dir.second;

            if (isValid(next_x, next_y) && grid[next_x][next_y] == '1') {
                stack.emplace(next_x, next_y);
            }
        }
    }
}

