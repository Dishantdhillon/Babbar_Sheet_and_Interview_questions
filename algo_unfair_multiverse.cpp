#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    long long int sum = 0;
    for(int i=1; i<n; i++) {
        sum += abs(arr[i] - arr[i-1])
    }
    
    return 0;
}