#include<bits/stdc++.h>
using namespace std;

int FindMaxSum(int arr[], int n) {
    int incl = arr[0];
    int excl = 0, excl_new;
    for(int i=1; i<n; i++) {
        excl_new = max(incl, excl);
        incl = excl + arr[i];
        excl = excl_new;
    }
    return max(incl, excl);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << FindMaxSum(arr, n);
    return 0;
}
