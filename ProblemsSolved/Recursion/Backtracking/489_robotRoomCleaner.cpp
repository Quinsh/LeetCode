#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define btoe(x) (x).begin(), (x).end()
#define pb push_back

const int INF = 1e9;
const int MOD = 1e9 + 7;

/**
 * DATE: 2024.07.21
 * INTUITION:
 * 
 * TC: O(N) - for number of rooms
 * SC: O(N) - set used & also the recursion stack in the worst case
 * 
 * TOIMPROVE: 
 */
class Solution {
private:
    set<pair<int, int>> visited;
    vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
public:
    void cleanRoom(Robot& robot) {
        clean(robot, 0, 0, 0);
    }

    void clean(Robot &robot, int x, int y, int d) {
        robot.clean();
        visited.insert({x, y});
        for(int i=0; i<4; i++) {
            int new_d = (d+i)%4;
            int new_x = x+directions[new_d].first, new_y = y+directions[new_d].second;
            if (visited.count({new_x, new_y}) <= 0 && robot.move()) {
                clean(robot, new_x, new_y, new_d);
                goBack(robot);
            }
            robot.turnRight();
        }
    }

    void goBack(Robot &robot) {
        robot.turnLeft(); robot.turnLeft();
        robot.move();
        robot.turnLeft(); robot.turnLeft();
    }
};


// This is the robot's control interface.
// You should not implement it, or speculate about its implementation
class Robot {
    public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();
};
 