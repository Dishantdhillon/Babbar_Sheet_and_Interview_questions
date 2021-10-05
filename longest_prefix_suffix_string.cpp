#include<bits/stdc++.H>
using namespace std;

int lps(string s) {
    int n = s.length();
    int i = 1, len = 0;
    while(i < n) {
        if(s[i] == s[len]) {
            i++;
            len++;
        }
        else {
            i = i - len + 1;
            len = 0;
        }
    }
    return len;
}

int main() {
    string s;
    cin >> s;
    cout << lps(s);
    return 0;
}