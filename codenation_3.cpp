#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n) {
    for(int i=0; i<n; i++) {
        arr[i] = arr[i]%3;
    }
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            count0++;
        }
        else if(arr[i] == 1) {
            count1++;
        }
        else {
            count2++;
        }
    }
    if(count2 != n/3) {
        return -1;
    }
    if(count0 != n/3 + n%3 > 0 ? 1 : 0) {
        return -1;
    }
    if(count1 != n/3 + n% > 1 ? 1 : 0) {
        return -1;
    }
    int count = 0;
    map<int, int> mp;
    for(int i=0; i<n; i++) {
        mp[arr[i]] = i%3;
    }
    for(auto it = mp.begin(); it != mp.end(); it++) {
        if(it -> first != it -> second) {
            count++;
        }
    }
    return ceil(double(count)/double(2));
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, n) << endl;
    }
    return 0;
}
