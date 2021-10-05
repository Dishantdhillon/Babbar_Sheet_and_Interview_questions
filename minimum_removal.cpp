#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int count_removal(int arr[], int n, int k, int i, int j) {
    if(i >= j) {
        return 0;
    }
    if(abs(arr[j] - arr[i]) <= k) {
        return 0;
    }
    else if(dp[i][j] != -1) {
        return dp[i][j];
    }
    else if(arr[j] - arr[i] > k) {
        dp[i][j] = 1 + min(count_removal(arr, n, k, i+1, j), count_removal(arr, n, k, i, j-1));
    }
    return dp[i][j];
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    memset(dp, -1, sizeof(dp));
    if(n == 1) {
    	cout << 0;
	}
	else
    	cout << count_removal(arr, n, k, 0, n-1);
    return 0;
}
