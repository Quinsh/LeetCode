include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * DATE: 2024.06.19
 * INTUITION: while doing DFS, create nodes and link them to neighbors. No. actually this is harder than I thought if we are not using recursion.
 * using recursion: cloneGraph() returns a complete copy of graph, then connect that graph - both directions - to the node from where we called cloneGraph();
 * No. We need to use a map to record the nodes we went. 
 * 
 * TC: O(nodes+edges)
 * SC: O(nodes)
 * 
 * TOIMPROVE: think of way to do with bfs as well.
*/
unordered_map<Node*, Node*> map;

Node* cloneGraph(Node* node) {
    // base case
    if (node == nullptr) return node;

    Node *newnode = new Node(node->val);

    map[node] = newnode;

    for (const auto &neighbor : node->neighbors) {
        if (map.count(neighbor) <= 0) {
            newnode->neighbors.push_back(cloneGraph(neighbor));
        }
        else {
            newnode->neighbors.push_back(map[neighbor]);
        }
    }
    return newnode;
}
