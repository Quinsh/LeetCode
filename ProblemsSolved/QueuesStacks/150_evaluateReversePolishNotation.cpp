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
 * DATE: 2024.06.17
 * INTUITION: just use stack to evaluate the expression from start to back?
 * 
 * TC: O(N) - one pass algorithm.
 * SC: O(N) - stack grows at most up to like ~1/2 the length of tokens (if the operations are all at the end)
 * 
 * TOIMPROVE: 
*/
int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    unordered_map<string, function<int(int, int)>> fxns = {
        {"+", [](int a, int b) {return a+b; }},
        {"-", [](int a, int b) {return a-b; }},
        {"*", [](int a, int b) {return a*b; }},
        {"/", [](int a, int b) {return a/b; }},
    };

    for (int i = 0; i < tokens.size(); i++) {
        string cur = tokens[i];
        if (cur == "+" || cur == "-" || cur == "*" || cur == "/") {
            int ans = 0;
            int right = stack.top();
            stack.pop();
            int left = stack.top();
            stack.pop();
            function<int(int, int)> fxn = fxns[cur];
            ans = fxn(left, right);
            stack.push(ans);
        }
        else {
            stack.push(stoi(cur));
        }
    }
    return stack.top();
}
