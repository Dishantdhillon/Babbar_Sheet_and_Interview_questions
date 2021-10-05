#include<bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
    int count1 = __builtin_popcount(a);
    int count2 = __builtin_popcount(b);
    if(count1 <= count2) {
        return false;
    }
    return true;
}

void sort_set_bits(int arr[], int n) {
    stable_sort(arr, arr+n, cmp);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort_set_bits(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
