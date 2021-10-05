#include<bits/stdc++.h>
using namespace std;

bool find_difference(int arr[], int n, int k) {
    sort(arr, arr+n);
    int i = 0, j = 1;
    while(i < n && j < n) {
        if(i != j && (arr[j] - arr[i]) == k) {
            return true;
        }
        else if(arr[j] - arr[i] < k){
            j++;
        }
        else {
            i++;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << find_difference(arr, n, k);
    return 0;
}
