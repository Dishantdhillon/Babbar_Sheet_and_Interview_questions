#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
    int i=0,j=0,k=n-1;
    while(i<=k && j<m) {
        if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            swap(arr1[j++], arr2[k--]);
        }
    }
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
}

int main() {
    int n, m;
    cin >> n;
    int arr1[n];
    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }
    cin >> m;
    int arr2[m];
    for (int i=0; i<m; i++) {
        cin >> arr2[i];
    }
    merge(arr1, arr2, n, m);
    for(int i=0; i<n; i++) {
        cout << arr1[i];
    }
    for(int i=0; i<m; i++) {
        cout << arr2[i];
    }
    return 0;
}
