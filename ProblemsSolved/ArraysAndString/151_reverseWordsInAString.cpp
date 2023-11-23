//
// Created by Gun woo Kim on 11/22/23.
//
// Good exercise to practice breaking down strings into words.
// Although I didn't solve in this way...
#include <vector>
#include <string>
using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end());

    // erase multiple ' '
    int i = 0, len = s.size();
    while (i < len-1){
        if (s[i] == ' ' && s[i+1] == ' '){
            s.erase(i, 1);
            len--;
        }
        else{
            i++;
        }
    }
    // erase at the beginning and end
    i = 0;
    while(s[i]==' '){
        s.erase(i, 1);
    }
    i = s.size()-1;
    while(s[i]==' '){
        s.erase(i, 1);
        i--;
    }

    // reverse the order of words
    int l = 0, r = 0;
    for (r = 0; r < s.size(); r++){
        if (r == s.size()-1 || s[r+1] == ' '){
            reverse(s.begin()+l, s.begin()+r+1);
            if (r != s.size()-1){
                l = r+2;
            }
        }
    }

    return s;
}

/* // Take a look at this solution too. This involves dividing string into words.
string reverseWords(string s) {
    vector<string> words;
    stringstream ss(s);
    string tmp;
    while (ss >> tmp)
        words.push_back(tmp);

    string ans;
    for (int i = words.size() - 1; i >= 0; --i) {
        if (i != words.size() - 1) ans += " ";
        ans += words[i];
    }
    return ans;
}
*/