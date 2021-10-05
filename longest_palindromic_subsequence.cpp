#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, int n1, string s2, int n2) {
    int dp[n1+1][n2+1];
    for(int i=0; i<n1+1; i++) {
        for(int j=0; j<n2+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n1][n2];
}

int lps(string str) {
    string temp = str;
    reverse(temp.begin(), temp.end());
    return lcs(str, str.length(), temp, temp.length());
}

int main() {
    string str;
    cin >> str;
    cout << lps(str);
    return 0;
}
