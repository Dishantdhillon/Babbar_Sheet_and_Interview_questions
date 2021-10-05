#include<bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x)
{
    int min_length = n + 1, sum = 0, end = 0, start = 0;
    while(end < n) {
        while(sum <=x && end < n) {
            sum = sum + arr[end++];
        }
        while(sum > x && start < n) {
            if(end - start < min_length) {
                min_length = end - start;
            }
            sum = sum - arr[start++];
        }
    }
    return min_length;
}

int main() {
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << sb(arr, n, x);
    return 0;
}
