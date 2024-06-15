#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/**
 * INTUITION: do BFS from the gates. When a route overrides a room already reached through BFS from other gate, change it to the minimum btw them.
 * then, go through all the grid, and fill those that weren't reached with INF. Actually, no need to, bcz they are already INF.
 * 
*/

struct pos {
    int i;
    int j;
    bool operator<(const pos& other) const {
        return tie(i, j) < tie(other.i, other.j);
    }
};

void wallsAndGates(vector<vector<int>>& rooms) {
    for (int i = 0; i < rooms.size(); ++i) {
        for (int j = 0; j < rooms[i].size(); ++j) {
            // if it's a gate, perform BFS.
            if (rooms[i][j] == 0) {
                BFSfromGate(rooms, i, j);
            }
        }
    }
}

void BFSfromGate(vector<vector<int>>& rooms, int i, int j) {
    queue<pos> q;
    set<pos> went;
    q.push(pos{i, j});
    went.insert(pos{i, j});

    int cnt = 1;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
        int q_size = q.size();
        for (int k = 0; k < q_size; ++k) {
            pos cur = q.front();
            q.pop();

            for (const auto& dir : directions) {
                int newi = cur.i + dir[0];
                int newj = cur.j + dir[1];

                // validating if it's in the range of blocks
                if (newi < 0 || newi >= rooms.size() || newj < 0 || newj >= rooms[0].size())
                    continue;

                // validating if it's in `went`
                if (went.find(pos{newi, newj}) != went.end())
                    continue;

                if (rooms[newi][newj] > cnt) {
                    rooms[newi][newj] = cnt;
                    went.insert(pos{newi, newj});
                    q.push(pos{newi, newj});
                }
            }
        }
        cnt++;
    }
}