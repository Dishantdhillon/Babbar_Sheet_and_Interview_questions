#include<bits/stdc++.h>
using namespace std;

int pair_sum_array(int arr[], int n, int k) {
    int count = 0;
    for(int i=0; i<n; i++) {
        
    }
}

int mai() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n ; i++) {
        cin >> arr[i];
    }
    int count = pair_sum_array(arr, n, k);
    cout << count;
    return 0;
}