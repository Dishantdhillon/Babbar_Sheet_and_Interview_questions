#include<bits/stdc++.h>
using namespace std;

long long int max(long long int a, long long int b) {
	if(a > b) {
		return a;
	}
	return b;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int left[n], right[n];
    left[0] = 0;
    for(int i=1; i<n; i++) {
        left[i] = max(left[i-1] + arr[i-1], arr[i-1]);
    }
    right[n-1] = 0;
    for(int i=n-2; i>=0; i--) {
        right[i] = max(right[i+1] + arr[i+1], arr[i+1]);
    }
    /*for(int i=0; i<n; i++) {
    	cout << left[i] << " " << arr[i] << " " << right[i] << endl;
	}*/
    long long int sum = 0;
    int l = 0, r = 0;
    for(int i=0; i<n; i++) {
        if(left[i] > 0) {
            l = left[i];
        }
        if(right[i] > 0) {
            r = right[i];
        }
        sum = max(sum, pow(arr[i], 2) + l + r);
        l = 0;
        r = 0;
    }
    cout << sum;
    return 0;
}
