#include<bits/stdc++.h>
using namespace std;

int sum2(int a[], int n, int x, int i) {
    int left = i+1, right = n-1;
    while(left < right) {
        if(a[left] + a[right] == x) {
            return 1;
        }
        else if(a[left] + a[right] > x) {
            right--;
        }
        else {
            left++;
        }
    }
    return 0;
}
bool find3Numbers(int A[], int n, int X)
{
    sort(A, A+n);
    for(int i=0; i<n; i++) {
        if(sum2(A, n, X-A[i], i) == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << find3Numbers(arr, n ,x);
    return 0;
}
