#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int brr[], int n) {
    if(arr[0] < brr[0]) {
        return 0;
    }
    int ans1 = 0, ans2 = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] < brr[0]) {
            ans1 = i;
            break;
        }
    }
    for(int i=0; i<n; i++) {
        if(brr[i] > arr[0]) {
            ans2 = i;
            break;
        }
    }
    if(ans1 < ans2) {
        return ans1;
    }
    else {
        return ans2;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n], brr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        for(int i=0; i<n; i++) {
            cin >> brr[i];
        }
        cout << solve(arr, brr, n) << endl;
    }
    return 0;
}
