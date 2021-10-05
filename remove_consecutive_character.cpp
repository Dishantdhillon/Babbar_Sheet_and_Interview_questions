#include<bits/stdc++.h>
using namespace std;

string removeConsecutiveCharacter(string s) {
    string result;
    for(int i=1; i<s.length(); i++) {
        if(s[i-1] != s[i]) {
            result = result + s[i-1];
        }
    }
    return result + s[s.length()-1];
}

int main() {
    string str;
    cin >> str;
    cout << removeConsecutiveCharacter(str);
    return 0;
}