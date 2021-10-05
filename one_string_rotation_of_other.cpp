#include<bits/stdc++.h>
using namespace std;

bool rotation(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    if(n != m) {
        return 0;
    }
    string temp = s1 + s1;
    return (temp.find(s2) != string::npos);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << rotation(s1, s2);
}
