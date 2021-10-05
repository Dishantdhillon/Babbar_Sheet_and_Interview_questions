#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        long int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        long long int sum = 0;
        if(n == 1) {
            cout << 0 << endl;
        }
        else {
            long long int k = arr[0] & arr[1];
            for(int i=2; i<n; i++) {
                k = k & arr[i];
            }
            for(int i=0; i<n; i++) {
                sum += arr[i] ^ k;
            }
            cout << sum << endl;
        }
    }
    return 0;
}
