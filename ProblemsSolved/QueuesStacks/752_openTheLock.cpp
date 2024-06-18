#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

/**
 * INTUITION: start from '0000' and do BFS to locate the minimum step to every state. It can move to 8 different directions every state: 
 * 1000, 0100, 0010, 0001, -1 000, 0 -1 00, 00 -1 0, 000 -1
 * 
 * TC: 10^4. It will not visit visited states again, so the TC is just the size of the map.
 * SC: 4 (so O(1)). This is the width of the map (the lock has 4 digits), and the SC of BFS is restricted to min(M, N) where M,N are width and height of the grid.
 * 
 * TOIMPROVE: 
*/
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> set;
    unordered_set<string> deadend_set(deadends.begin(), deadends.end());
    queue<string> queue;
    int cnt = 0;
    queue.push("0000");
    set.insert("0000");

    if (deadend_set.find("0000") != deadend_set.end()) return -1;
    
    while(!queue.empty()) {
        int size = queue.size();

        for(int i = 0; i < size; i++) {
            string curstate = queue.front();
            queue.pop();

            if (curstate == target) return cnt;

            for (int k = 0; k < 4; k++) {
                string digitup = curstate;
                string digitdown = curstate;

                digitup[k] = digitup[k] == '9' ? '0' : (digitup[k] - '0' + 1) + '0';
                digitdown[k] = digitdown[k] == '0' ? '9' : (digitdown[k] - '0' -1) + '0';

                if (set.find(digitup) == set.end() && deadend_set.find(digitup) == deadend_set.end()) {
                    set.insert(digitup);
                    queue.push(digitup);
                }
                if (set.find(digitdown) == set.end() && deadend_set.find(digitdown) == deadend_set.end()) {
                    set.insert(digitdown);
                    queue.push(digitdown);
                }
            }
        }
        cnt++;
    }
    return -1;
}