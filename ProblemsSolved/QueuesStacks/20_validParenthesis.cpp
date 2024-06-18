#include <string>
#include <stack>

using namespace std;
/**
 * INTUITION: well easy classic parenthesis problem.
 * 
 * TC:
 * SC: 
 * 
 * TOIMPROVE: 
*/
bool isValid(string s) {
    stack<int> stack;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack.push(s[i]);
        }
        else{
            if (stack.empty()) return false;
            int top = stack.top();
            if (top == '(' && s[i] == ')' ||
                top == '[' && s[i] == ']' ||
                top == '{' && s[i] == '}'){  
                stack.pop();
            }
            else{
                return false;
            }
        }
    }
    if (stack.empty()) return true;
    else return false;
}
