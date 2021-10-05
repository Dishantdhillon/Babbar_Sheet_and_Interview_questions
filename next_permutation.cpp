#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    b = a + b;
    a = b - a;
    b = b - a;
}

void reverse_array(int arr[], int n) {
    for(int i=0; i<n/2; i++) {
        swap(arr[i], arr[n-i-1]);
    }
}

void next_permutation(int arr[], int n) {
    int i,j,k=0;
    for(i=n-1; i>0; i--) {
        if(arr[i] > arr[i-1]) {
            j = i;
            while(j < n) {
                k = arr[j] - arr[i-1];
                if(k < 0) {
                    swap(arr[i-1], arr[j-1]);
                    sort(arr+i, arr+n);
                    return;
                }
                j++;
            }
            swap(arr[i-1], arr[j-1]);
            sort(arr+i, arr+n);
            return;  
        }
    }
    reverse_array(arr, n);
    return;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    next_permutation(arr, n);
    for(int i=0; i<n; i++) {
    	cout << arr[i] << " ";
	}
    return 0;
}
