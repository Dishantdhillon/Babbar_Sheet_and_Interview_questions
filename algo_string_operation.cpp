#include<bits/stdc++.h>
using namespace std;

void reverse_(string &s, int start) {
    int n = s.length();
    for(int i=start-1; i<= start-1+(n-(2*start)+1)/2; i++) {
        swap(s[i], s[n-i-1]);
    }
}

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    int arr[m];
    for(int i=0; i<m; i++) {
        cin >> arr[i];
    }
    int n = s.length();
    for(int i=0; i<m; i++) {
        reverse_(s, arr[i]);
    }
    cout << s;
}
