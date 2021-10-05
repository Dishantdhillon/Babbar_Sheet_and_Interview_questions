#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n) {
    for(int i=0; i<n/2; i++) {
        swap(arr[i], arr[n-1-i]);
    }
}

void next_permutation(int arr[], int n) {
    int count = 0;
    for(int i=n-1; i>=1; i--) {
        if(arr[i] > arr[i-1]) {
            int j = i+1;
            while(j < n && arr[j] > arr[i-1]) {
            	j++;
			}
			swap(arr[j-1], arr[i-1]);
            sort(arr+i, arr+n);
            break;
        }
        else {
            count++;
        }
    }
    if(count == n-1) {
        reverse(arr, n);
    }
    return;
}

int main() {
    int n, k;
    cin >> n >> k;
    while(k--) {
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        next_permutation(arr, n);
        for(int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
