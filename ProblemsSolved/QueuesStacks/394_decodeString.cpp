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
 * INTUITION: pretty easy. while iterating through the string, we have two options: either it's a char or number. 
 *              1. If it's a number there will be [bracket] after that, so decode that recursively and multiply by that number and add it to the answer string. 
 *              2. If it's a character just add it to the answer string.
 * 
 * But this question is annoying in the sense that there is lot of index calculation going on and it's easy to lose track.
 * 
 * TC: Approximately O(n)
 * SC: O(n)
 * 
 * TOIMPROVE: 
*/
class Solution394 {
public:
    string decodeString(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                int numlen = numLen(s, i);
                int bracklen = matchingBracketLen(s, i+1);
                int num = stoi(s.substr(i, numlen));
                i += numlen;
                string substring = s.substr(i + 1, bracklen);
                string decoded = decodeString(substring);
                for (int j = 0; j < numlen; j++) {
                    ans.append(decoded);
                }
                i += bracklen + 2;
            }
            else {
                ans += c;
            }

        }
        return ans;
    }

    int matchingBracketLen(const string &s, int i) {
        // given some string `[df[ss]]see`, counts the length of `df[ss]`
        int cnt = 1;
        stack<char> stack;
        stack.push(s[i++]);
        while (!stack.empty()) {
            if (s[i] == '[') {
                stack.push('[');
            }
            else if (s[i] == ']') {
                stack.pop();
            }
            i++;
            cnt++;
        }
        return cnt - 2;
    }

    int numLen(const string &s, int i) {
        int cnt = 0;
        for (int j = i; j < s.size(); j++) {
            if (s[j] >= '0' && s[j] <= '9') cnt++;
            else return cnt;
        }
        return cnt;
    }
};