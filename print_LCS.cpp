#include<bits/stdc++.h>
using namespace std;

static int dp[1000][1000];

string print_LCS(string x, string y, int n, int m) {
    string result;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(x[i-1] == y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = n, j = m;
    while(i>=0 && j>=0) {
    	if(x[i] == y[j]) {
    		result = result + x[i];
    		i--;
    		j--;
		}
		else {
			if(dp[i-1] > dp[j-1]) {
				i--;
			}
			else {
				j--;
			}
		}
	}
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string x, y;
    cin >> x >> y;
    cout << print_LCS(x, y, x.length(), y.length());
    return 0;
}
