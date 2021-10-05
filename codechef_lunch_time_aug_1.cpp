#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int maxE = INT_MIN, ans = 0;
        for(int i=0; i<n; i++) {
            maxE = max(arr[i], maxE);
        }
        if(maxE == arr[k-1]) {
            ans++;
        }
        for(int i=k; i<n; i++) {
            if(arr[i] == maxE) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
