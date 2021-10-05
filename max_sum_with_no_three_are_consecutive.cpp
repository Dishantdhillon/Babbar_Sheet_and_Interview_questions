#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr[], int n) {
    int sum[n];
    if(n >= 1) {
        sum[0] = arr[0];
    }
    if(n >= 2) {
        sum[1] = arr[0] + arr[1];
    }
    if(n >= 3) {
        sum[2] = max(max(sum[1], arr[0] + arr[2]), arr[1] + arr[2]);
    }
    for(int i=3; i<n; i++) {
        sum[i] = max(max(sum[i-1], sum[i-2] + arr[i]), arr[i] + arr[i-1] + sum[i-3]);
    }
    return sum[n-1];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << max_sum(arr, n);
    return 0;
}
