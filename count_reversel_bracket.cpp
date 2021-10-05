#include <bits/stdc++.h>
using namespace std;

int countRev (string x) {
    stack<char> exp;
    int n = x.length(), count_o = 0, count_c = 0;
    if(n == 0) {
        return 0;
    }
    if(n % 2 == 1) {
        return -1;
    }
    for(int i=0; i<n; i++) {
        if(exp.empty()) {
            exp.push(x[i]);
            if(exp.top() == '{') {
                count_o++;
            }
            else {
                count_c++;
            }
        }
        else if(x[i] == '{' && exp.top() == '}') {
            exp.push(x[i]);
            count_o++;
        }
        else if(x[i] == '}' && exp.top() == '{') {
            exp.pop();
            count_o--;
        }
        else if(x[i] == '}' && exp.top() == '}') {
            exp.push(x[i]);
            count_c++;
        }
        else if(x[i] == '{' && exp.top() == '{') {
            exp.push(x[i]);
            count_o++;
        }
    }
    if(exp.size() == 0) {
        return 0;
    }
    return (count_o + count_c)/2 + count_o%2;
}

int main() {
    string s;
    cin >> s;
    cout << countRev(s);
}