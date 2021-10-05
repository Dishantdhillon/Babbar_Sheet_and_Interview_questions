#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right);
int _inversion_count(int arr[], int temp[], int left, int right);

int inversion_count(int arr[], int n) {
    int temp[n];
    return _inversion_count(arr, temp, 0, n-1);
}

int _inversion_count(int arr[], int temp[], int left, int right) {
    int mid, count = 0;
    while(left < right) {
        mid = left + (right-left)/2;
        count = count + _inversion_count(arr, temp, left, mid);
        count = count + _inversion_count(arr, temp, mid+1, right);
        count = count + merge(arr, temp, left, mid+1, right);
    }
    return count;
}

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left, count = 0;
    while((i <= mid-1) && (j <= right)) {
       if(arr[i] <= arr[j]) {
           temp[k++] = arr[i++];
       } 
       else {
           temp[k++] = arr[j++];
           count = count + mid - i;
       }
    }
    while(i <= mid-1) {
        temp[k++] = arr[i++];
    }
    while(j <= right) {
        temp[k++] = arr[j++];
    }
    for(int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[n];
    }
    int output = inversion_count(arr, n);
    cout << output;
    return 0;
}
