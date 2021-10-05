#include<bits/stdc++.h>
using namespace std;

int main() {
	cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while(t--) {
        int n, ma = INT_MIN;
        long long int sum = 0;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            sum += arr[i];
            ma = max(arr[i], ma);
        }
        cout << double(ma + double(sum - ma)/double(n-1)) << endl;
    }
    return 0;
}
