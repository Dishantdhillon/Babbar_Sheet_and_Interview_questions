#include<bits/stdc++.h>
using namespace std;

class Solution {    
    public:
        int minT(int x, int y, int z) {
            return min(min(x, y), z);
        }
        
        /*int editDistanceRec(string s, string t, int m, int n) {
            if(m == 0) {
                return n;
            }
            if(n == 0) {
                return m;
            }
            if(s[m-1] == t[n-1]) {
                return editDistanceRec(s, t, m-1, n-1);
            }
            return 1 + minT(editDistanceRec(s, t, m, n-1), editDistanceRec(s, t, m-1, n), editDistanceRec(s, t, m-1, n-1));
        }
        */
        int editDistanceRec(string s, string t, int m, int n) {
            int dp[m+1][n+1];
            for(int i=0; i<=m; i++) {
                for(int j=0; j<=n; j++) {
                    if(i==0) {
                        dp[i][j] = j;
                    }
                    else if(j==0) {
                        dp[i][j] = i;
                    }
                    else if(s[i-1] == t[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else {
                        dp[i][j] = 1 + minT(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
                    }
                }
            }
            return dp[m][n];
        }
        
        int editDistance(string s, string t) {
            return editDistanceRec(s, t, s.length(), t.length());
        }
};


int main() {
    string s, t;
    cin >> s >> t;
    Solution obj;
    cout << obj.editDistance(s, t);
}
