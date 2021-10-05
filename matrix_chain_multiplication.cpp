#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int matrix_chain_multiplication(int arr[], int n, int i, int j) {
    if(i >= j) {
        return 0;
    }
    int temp, ans = INT_MAX;
    if(dp[i][j] != -1) {
    	return dp[i][j];
	}
    for(int k=i; k<j; k++) {
        temp = matrix_chain_multiplication(arr, n, i, k) + matrix_chain_multiplication(arr, n, k+1, j) + arr[i-1] * arr[k] * arr[j];
        ans = min(temp, ans);
    }
    return dp[i][j] = ans;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << matrix_chain_multiplication(arr, n, 1, n-1);
    return 0;
}
