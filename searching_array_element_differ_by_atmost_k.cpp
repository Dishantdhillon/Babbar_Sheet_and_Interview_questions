#include<bits/stdc++.h>
using namespace std;

int searching(int arr[], int n, int k, int x) {
    int diff;
    for(int i=0; i<n; ) {
        diff = abs(arr[i] - x);
        if(diff == 0) {
            return i;
        }
        i += max(1, diff/k);
    } 
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int k, x;
    cin >> k >> x;
    cout << searching(arr, n, k, x);
    return 0;
}