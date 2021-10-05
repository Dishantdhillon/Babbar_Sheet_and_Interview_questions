#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    b = b + a;
    a = b - a;
    b = b - a;
}

void rotate(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        swap(arr[i], arr[n-1]);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    rotate(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
