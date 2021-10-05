#include<bits/stdc++.h>
using namespace std;

int min_jump(int arr[], int n) {
    int output = 0, i=0;
    while(i<n) {
        if(arr[i] == 0) {
            return 0;
        }
        int j = arr[i];
        if(i != n-1) {
        	output++;
    	}
        i = i + j;
    }
    return output;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int output = min_jump(arr, n);
    cout << output;
    return 0;
}
