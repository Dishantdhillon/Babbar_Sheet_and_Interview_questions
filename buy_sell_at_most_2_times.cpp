#include<bits/stdc++.h>
using namespace std;

int buy_sell(int arr[], int n) {
    vector<int> v(n, 0);
    int max_price = arr[n-1];
    for(int i=n-2; i>=0; i--) {
        if(arr[i] > max_price) {
            max_price = arr[i];
        }
        v[i] = max(v[i+1], max_price-arr[i]);
    }
    int min_price = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] < min_price) {
            min_price = arr[i];
        }
        v[i] = max(v[i-1], v[i] + arr[i] - min_price);
    }
    return v[n-1];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << buy_sell(arr, n);
    return 0;
}
