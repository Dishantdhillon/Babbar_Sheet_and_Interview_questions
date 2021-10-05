#include<bits/stdc++.h>
using namespace std;

const long long int N = 1e5;

long long int gcd(long long int a, long long int b) {
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    }
    if(a == b) {
        return a;
    }
    if(a > b) {
        return gcd(a-b, b);
    }
    return gcd(a, b-a);
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        long long int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int arr1[N];
		int arr2[N]; 
		sort(arr, arr+n);
        arr1[0] = arr[0];
        for(int i=1; i<n; i++) {
            arr1[i] = gcd(arr[i], arr1[i-1]);
        }
        arr2[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--) {
            arr2[i] = gcd(arr[i], arr2[i+1]);
        }
        int sum = 0, ans = 1e6, m;
        for(int i=0; i<n; i++) {
        	sum = sum + arr[i];
		}
        for(int i=0; i<n; i++) {
        	m = (sum - arr[i] + gcd(arr1[i-1], arr2[i+1]))/gcd(arr1[i-1], arr2[i+1]);
        	ans = min(ans, m);
		}
        cout << ans << endl;
    }
    return 0;
}
