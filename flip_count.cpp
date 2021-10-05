#include<bits/stdc++.h>
using namespace std;

char flip(char ch) {
    if(ch == '0') {
        return '1';
    }
    else {
        return '0';
    }
}

int flips_expected(string s, char expected) {
    int flipcount = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] != expected) {
            flipcount++;
        }
        expected= flip(expected);
    }
    return flipcount;
}

int minFlips (string s) {
    return min(flips_expected(s, '0'), flips_expected(s, '1'));
}

int main() {
    string s;
    cin >> s;
    cout << minFlips(s);
    return 0;
}
