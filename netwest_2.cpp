#include<bits/stdc++.h>
using namespace std;

long int min(long int a, long int b) {
	if(a < b) {
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
    long int prev = INT_MAX, curr = INT_MAX;
    for(int i=0; i<n; i++) {
        prev = min(prev + arr[i], arr[i]);
        curr = min(prev, curr);
    }
    cout << curr;
    return 0;
}
