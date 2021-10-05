#include<bits/stdc++.h>
using namespace std;

int space_optimized_lcs(string s1, string s2, int n, int m) {
    int dp[2][m+1];
    bool bi;
    for(int i=0; i<n+1; i++) {
        bi = i & 1;
        for(int j=0; j<m+1; j++) {
            if(i == 0 || j == 0) {
                dp[bi][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]) {
                dp[bi][j] = 1 + dp[1-bi][j-1];
            }
            else {
                dp[bi][j] = max(dp[1-bi][j], dp[bi][j-1]);
            }
        }
    }
    return dp[bi][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << space_optimized_lcs(s1, s2, s1.length(), s2.length());
    return 0;
}
