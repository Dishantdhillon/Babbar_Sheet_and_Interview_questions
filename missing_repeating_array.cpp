#include<bits/stdc++.h>
using namespace std;

int *missing_repeating(int arr[], int n) {
    int ans[2];
    for(int i=0; i<n; i++) {
        if(arr[abs(arr[i]) - 1] > 0) {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        else {
            ans[0] = abs(arr[i]);
        }
    }
    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            ans[1] = i+1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int *ans = missing_repeating(arr, n);
    cout << ans[0] << " " << ans[1];
    return 0;
}
