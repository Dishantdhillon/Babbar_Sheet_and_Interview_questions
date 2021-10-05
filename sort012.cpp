#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n) {
    // sort(arr, arr + n); using sort function with time complexity nlog(n)
    int count[3] = {0};
    for(int i=0; i<n; i++) {
        count[arr[i]]++;
    }
    for(int j=0; j<3; j++) {
        for(int i=0; i<count[j]; i++) {    
            cout << j << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort012(arr, n);
    return 0;
}
