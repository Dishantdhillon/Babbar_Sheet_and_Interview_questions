#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
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
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int brr[n];
        for(int i=0; i<n-1; i++) {
            brr[i] = gcd(arr[i], arr[i+1]);
        }
        brr[n-1] = gcd(arr[n-1], arr[0]);
    }
    return 0;
}