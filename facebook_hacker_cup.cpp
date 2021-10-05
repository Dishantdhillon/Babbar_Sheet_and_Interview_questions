#include<bits/stdc++.h>
using namespace std;

int solve(string str, int n) {
    int ans = 0;
    int flag = 0, i;
    for(i=0; i<n; i++) {
        if(str[i] == 'X') {
            flag = 1;
            break;
        }
        else if(str[i] == 'O') {
            flag = 2;
            break;
        }
    }
    if(flag == 0) {
        return 0;
    }
    for(int j=i+1; j<n; j++) {
        if(str[j] == 'X' && flag == 2) {
            ans++;
            flag = 1;
        }
        else if(str[j] == 'O' && flag == 1) {
            ans++;
            flag = 2;
        }
    }
    return ans;
}

int main() {
    int t, i = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        cout << "Case #" << i << ": " << solve(str, n) << endl;
        i++;
    }
    return 0;
}
