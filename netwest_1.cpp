#include<bits/stdc++.h>
using namespace std;

struct Result {
    Result() : output1(){}
    int output1[100];
};

Result alttab(int n, int k, int arr[]) {
	if(k%n == 0) {
        for(int i=k-1; i>=1; i--) {
            swap(arr[i], arr[i-1]);
        }
    }
    else {
        k = k % n;
        for(int i=k-1; i>=1; i--) {
            swap(arr[i], arr[i-1]);
        }
    }
    Result* re;
    re -> output1 = arr;
    return re;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    if(k%n == 0) {
        for(int i=k-1; i>=1; i--) {
            swap(arr[i], arr[i-1]);
        }
    }
    else {
        k = k % n;
        for(int i=k-1; i>=1; i--) {
            swap(arr[i], arr[i-1]);
        }
    }
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
