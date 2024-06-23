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
 * DATE: 2024.06.22
 * INTUITION: do starting from the first, mark visited rooms, and return visited.len == rooms.len
 * 
 * TC: O(Rooms * Keys) - O(sum of all keys across the rooms) to be more accurate ==> O(V+E)
 * SC: O(sum of keys) - since we are using stack<vector<int>>, the worst case would be that the first room contains keys for all rooms. 
 * Then, we end up storing all rooms in the stack with all the keys. So O(E) or O(V+E) to be more formal(?)
 * 
 * TOIMPROVE: 
*/
class Solution841 {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> set;
        stack<vector<int>> s;
        
        s.push(rooms[0]);
        set.insert(0);

        while (!s.empty()) {
            vector<int> cur = s.top();
            s.pop();

            for (const auto &i : cur) {
                if (set.find(i) == set.end()) {
                    set.insert(i);
                    s.push(rooms[i]);
                }
            }
        }
        return set.size() == rooms.size();
    }
};


