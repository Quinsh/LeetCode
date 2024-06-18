include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <unordered_map>
#include <unordered_set>

/**
 * DATE: 2024.06.18
 * INTUITION: easy bfs
 * 
 * TC: O(N)
 * SC: Min(Row, Col)
 * 
 * TOIMPROVE: 
*/
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> queue;
    int x_len = image.size();
    int y_len = image[0].size();
    int basecolor = image[sr][sc];

    queue.emplace(sr, sc);
    image[sr][sc] = color;
    
    while (!queue.empty()) {
        auto [x, y] = queue.front();
        queue.pop();

        for (const auto &dir : directions) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;

            if (new_x >= 0 && new_y >= 0 && new_x < x_len && new_y < y_len && image[new_x][new_y] == basecolor && image[new_x][new_y] != color) {
                image[new_x][new_y] = color;
                queue.emplace(new_x, new_y);
            }
        }
    }
    return image;
}