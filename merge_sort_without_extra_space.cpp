#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high);

void merge_sort(int arr[], int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int ma = max(arr[mid], arr[high]) + 1; 
    while(i <= mid && j <= high && k <= high) {
        int e1 = arr[i] % ma;
        int e2 = arr[j] % ma;
        if(e1 <= e2) {
            arr[k] = arr[k] + e1*ma;
            k++;
            i++;
        }
        else {
            arr[k] = arr[k] + e2*ma;
            k++;
            j++;
        }
    }
    while(i <= mid) {
        int e1 = arr[i] % ma;
        arr[k] = arr[k] + e1*ma;
        k++;
        i++;
    }
    while(j <= high) {
        int e2 = arr[j] % ma;
        arr[k] = arr[k] + e2*ma;
        k++;
        j++;
    }
    for(int i=low; i<=high; i++) {
        arr[i] = arr[i]/ma;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    merge_sort(arr, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
