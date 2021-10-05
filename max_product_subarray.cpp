#include<bits/stdc++.h>
using namespace std;

long long max(long long int a, long long int b) {
	return a > b ? a : b;
}
long long min(long long int a, long long int b) {
	return a < b ? a : b;
}

long long maxProduct(int arr[], int n) {
	long long int max_product = arr[0], minVal = arr[0], maxVal = arr[0];
	for(int i=1; i<n; i++) {
	    if(arr[i] < 0) {
	        long long int temp = minVal;
	        minVal = maxVal;
	        maxVal = temp;
	    }
	    maxVal = max(arr[i], arr[i]*maxVal);
	    minVal = min(arr[i], arr[i]*minVal);
	    max_product = max(max_product, maxVal);
	}
	return max_product;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << maxProduct(arr, n);
    return 0;
}