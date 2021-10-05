#include<bits/stdc++.h>
using namespace std;

bool is_valid(int arr[], int n, int mid, int c) {
    int count = 0;
    int pre = -1000000000;
    for(int i=0; i<n; i++) {
        if((arr[i] - pre) >= mid) {
            count++;
            pre = arr[i];
        }
    }
    if(count >= c) {
        return true;
    }
    else {
        return false;
    }
}

int max_min_distance(int arr[], int n, int c) {
    sort(arr, arr+n);
    int ans = 0;
    int low = 0, mid;
    int high = arr[n-1] - arr[0];
    while(low <= high) {
        mid = (high + low)/2;
        if(is_valid(arr, n, mid, c)) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cout << max_min_distance(arr, n, c) << endl;
    }
    return 0;
}
