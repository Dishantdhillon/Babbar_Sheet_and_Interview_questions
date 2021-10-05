#include<bits/stdc++.h>
using namespace std;

int is_majority(int arr[], int n, int cand) {
    int count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == cand) {
            count++;
        }
    }
    if(count > n/2) {
        return cand;
    }
    return -1;
}
    
int majorityElement(int arr[], int n) {
    int maj_index = 0, count = 1;
    for(int i=1; i<n; i++) {
        if(arr[maj_index] == arr[i]) {
            count++;
        }
        else{
            count--;
        }
        if(count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    return is_majority(arr, n, arr[maj_index]);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << majorityElement(arr, n);
    return 0;
}
