#include<iostream>
using namespace std;

void swap(int &a, int &b){
	b = a + b;
	a = b - a;
	b = b - a;
}

int k_smallest(int arr[], int n, int k) {
    int output = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] < output) {
            output = arr[i];
        }
    }
    return output;
}

int main() {
    int n;
    cin >> n;
    int arr[n], k;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cin >> k;
    int output = k_smallest(arr, n, k);
    cout << output;
    return 0;
}