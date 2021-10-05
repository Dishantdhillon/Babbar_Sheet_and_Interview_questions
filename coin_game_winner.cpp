#include<bits/stdc++.h>
using namespace std;

bool game_winner(int n, int x, int y) {
    bool dp[n+1];
    dp[0] = false;
    dp[1] = true;
    for(int i=2; i<=n; i++) {
        if(i - 1 >= 0 && dp[i-1] == false) {
            dp[i] = true;
        }
        else if(i - x >= 0 && dp[i-x] == false) {
            dp[i] = true;
        }
        else if(i - y >= 0 && dp[i-y] == false) {
            dp[i] = true;
        }
        else {
            dp[i] = false;
        }
    }
    return dp[n];
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    if(game_winner(n, x, y)) {
        cout << "A";
    }
    else {
        cout << "B";
    }
    return 0;
}