#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> left(n);
    vector<int> right(n);
    for(int i=0; i<n; i++) {
        if(i > 0) {
            left[i] = max(left[i-1] + arr[i], arr[i]);
        }
        else {
            left[i] = arr[i];
        }
    }
    for(int i=n-1; i>=0; i--) {
        if(i < n-1) {
            right[i] = max(right[i+1] + arr[i], arr[i]);
        }
        else {
            right[i] = arr[i];
        }
    }
    int ans = INT_MIN;
    for(int i=1; i<n-1; i++) {
        ans = max(ans, left[i-1]+right[i+1]);
    }
    int k = max(left[n-1], left[n-2]);
    int l = max(right[0], right[1]);
    k = max(k, l);
    ans = max(ans, k);
    cout << ans;
    return 0;
}
