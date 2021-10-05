#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
    int sum = 0;
    if(k < 2) {
        return 0;
    }
    if(k == 2) {
        return ceil(n/2.0);
    }
    for(int i=0; i<=n; i++) {
        if(solve(n-i, k-1) - (i + k - 2) > 0) {
            sum += solve(n-i, k-1) - (i + k - 2);
        }
        else {
            break;
        }
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}
