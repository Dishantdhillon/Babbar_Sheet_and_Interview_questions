#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr1[], int arr2[], int n, int m) {
    int sum = 0, sum1 = 0, sum2 = 0;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            sum1 += arr1[i++];
        }
        else if(arr1[i] > arr2[j]) {
            sum2 += arr2[j++];
        }
        else {
            sum = sum + max(sum1, sum2) + arr1[i];
            i++;
            j++;
            sum1 = 0;
            sum2 = 0;
        }
    }
    for(int l=i; l<n; l++) {
        sum1 += arr1[l];
    }
    for(int l=j; l<m; l++) {
        sum2 += arr2[l];
    }
    sum = sum + max(sum1, sum2);
    return sum;     
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
    for(int i=0; i<m; i++) {
        cin >> arr2[i];
    }
    cout << max_sum(arr1, arr2, n, m) << endl;
    return 0;
}
