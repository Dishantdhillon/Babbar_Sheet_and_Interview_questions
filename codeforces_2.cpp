#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        long long int arr[n];
        long long int sum = 0;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            sum = sum + arr[i];
        }
        long long int k = sum % n;
        long long int ans = k * (n - k);
        cout << ans << endl;
    }
    return 0;
}
