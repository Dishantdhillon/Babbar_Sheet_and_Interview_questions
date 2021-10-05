#include<bits/stdc++.h>
using namespace std;

bool is_valid(int arr[], int n, int m, int mid) {
    long long int count = 0;
    for(int i=0; i<n; i++) {
        if(mid < arr[i]) {
            count = count + arr[i] - mid;
        }
    }
    if(count >= m) {
        return true;
    }
    else {
        return false;
    }
}

int height(int arr[], int n, int m) {
    int max = arr[0];
    for(int i=0; i<n; i++) {
    	if(arr[i] > max) {
    		max = arr[i];
    	}
    }
    int ans = 0;
    int start = 0, end = max, mid;
    while(start <= end) {
        mid = (start + end)/2;
        if(is_valid(arr, n, m, mid)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << height(arr, n, m);
    return 0;
}
