//
// Created by Gun woo Kim on 11/18/23.
//
// thing to learn:
// do '2' - '0' to obtain 2 (integer)
// mystring += 2 + '0' adds '2' to my string. Bcz 2 + 48 --> 50 converts into str when doing +=

#include <vector>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    int i = a.size()-1, j = b.size()-1;
    string res;
    int cur = 0;

    while (i >= 0 || j >= 0 || cur!= 0){

        if (i >= 0) cur += a[i--] - '0';
        if (j >= 0) cur += b[j--] - '0';

        res += to_string(cur%2);
        cur /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}