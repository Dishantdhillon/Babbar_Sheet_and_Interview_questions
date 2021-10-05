#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string temp = s;
        sort(&temp[0], &temp[0]+n);
        int count = 0;
        for(int i=0; i<n; i++) {
            if(temp[i] != s[i]) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}